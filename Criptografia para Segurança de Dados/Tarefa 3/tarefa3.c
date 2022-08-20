/*
 *  Programa simples de chat
 *  Uso: ./chat <porta de entrada> <IP de destino> <porta a conectar> (ex. ./chat 7777 127.0.0.1 8888)
 *  OBS.: use portas entre 1024 e 65535
 *  Código obtido da internet, qualquer problema de compilação/execução deve ser reportado ao professor
 *
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <poll.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define TAM_MATRIX 27
#define TAM_TEXTO 1000
#define TAM_CHAVE 1

void start_chat(int sock_fd, struct sockaddr_in *peer);
// Fun��o para calcular `a^m mod n`
int compute(int a, int m, int n);
// Fun��o para fazer a chamada de outras fun�oes
int sorteia_chave();
// Cria uma nova chave incrementando a antiga de 10 em 10, ateh o intervalo de 97 - 122
int sorteia_nova_chave(int chave);
// Preenche os vetores com '%' para tirar o lixo de memoria
void inicializa_vetores(char vetor[], int tamanho);
// Imprime os vetores
void mostrar_vetores(char vetor[], int tamanho);
// Imprime a matrix
void mostrar_matrix(char vigenere_matrix[TAM_MATRIX][TAM_MATRIX]);
// Extende a chave ateh ficar do tamanho do texto informado pelo usuario
void extender_chave(char chave[], char chave_extendida[TAM_TEXTO],
                    char texto_cifrado[TAM_TEXTO], char texto[TAM_TEXTO],
                    char texto_decifrado[TAM_TEXTO], char matrix[TAM_MATRIX][TAM_MATRIX],
                    int tam_texto, int tam_chave, int sec);
// texto_cifrado = texto + chave_extendida
void cifrador_texto(char texto[TAM_TEXTO], char chave_extendida[TAM_TEXTO],
                    char texto_cifrado[TAM_TEXTO], char matrix[TAM_MATRIX][TAM_MATRIX],
                    int tam_texto);
// texto_decifrado = texto_cifrado + chave_extendida
void descifrador_texto(char texto[TAM_TEXTO], char chave_extendida[TAM_CHAVE],
                       char texto_cifrado[TAM_TEXTO], char matrix[TAM_MATRIX][TAM_MATRIX],
                       int tam_texto);
// Funcao sem ainda utilizcao
int tam_vet(char vetor[]);

int main(int argc, char *argv[]){
  unsigned long local_port;
  unsigned long remote_port;
  int sock_fd;
  struct sockaddr_in server_addr;
  struct sockaddr_in peer_addr;

  /* Parse command line arguments for port numbers */
  if (argc < 4){
    printf("Usage: %s <local port> <remote host> <remote port>\n", argv[0]);
    return 1;
  }
  local_port = strtoul(argv[1], NULL, 0);
  if (local_port < 1 || local_port > 65535){
    printf("Error - invalid local port '%s'\n", argv[1]);
    return 1;
  }
  remote_port = strtoul(argv[3], NULL, 0);
  if (remote_port < 1 || remote_port > 65535){
    printf("Error - invalid remote port '%s'\n", argv[3]);
    return 1;
  }

  /* Parse command line argument for remote host address */
  peer_addr.sin_family = AF_INET;
  peer_addr.sin_port = htons(remote_port);
  if (inet_aton(argv[2], &peer_addr.sin_addr) == 0){
    printf("Error - invalid remote address '%s'\n", argv[2]);
    return 1;
  }

  /* Create UDP socket */
  sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock_fd < 0){
    printf("Error - failed to open socket: %s\n", strerror(errno));
    return 1;
  }

  /* Bind socket */
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(local_port);
  if (bind(sock_fd, (struct sockaddr *)(&server_addr),
           sizeof(server_addr)) < 0){
    printf("Error - failed to bind socket: %s\n", strerror(errno));
    return 1;
  }

  /* Call chat handler to loop */
  start_chat(sock_fd, &peer_addr);

  close(sock_fd);

  return 0;
}

void start_chat(int sock_fd, struct sockaddr_in *peer){
  int ret;
  ssize_t bytes;
  char input_buffer[TAM_TEXTO];
  char output_buffer[TAM_TEXTO];
  struct pollfd fds[2];

  /*##########################################################*/
  int cif_ou_dec = 0;
  char key_letra[TAM_CHAVE];
  char texto[TAM_TEXTO];
  char texto_cifrado[TAM_TEXTO];
  char texto_decifrado[TAM_TEXTO];
  char chave_extendida[TAM_TEXTO];
  inicializa_vetores(chave_extendida, TAM_TEXTO);
  inicializa_vetores(texto_cifrado, TAM_TEXTO);
  inicializa_vetores(texto_decifrado, TAM_TEXTO);
  inicializa_vetores(texto, TAM_TEXTO);
  char vigenere_matrix[TAM_MATRIX][TAM_MATRIX] = {
      {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
      {'a', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
      {'b', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a'},
      {'c', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b'},
      {'d', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c'},
      {'e', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd'},
      {'f', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e'},
      {'g', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f'},
      {'h', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g'},
      {'i', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
      {'j', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'},
      {'k', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'},
      {'l', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'},
      {'m', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'},
      {'n', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'},
      {'o', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'},
      {'p', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o'},
      {'q', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'},
      {'r', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q'},
      {'s', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'},
      {'t', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's'},
      {'u', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'},
      {'v', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u'},
      {'w', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v'},
      {'x', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w'},
      {'y', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x'},
      {'z', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y'}};

  key_letra[0] = sorteia_chave();

  /*##########################################################*/

  /* Descriptor zero is stdin */
  fds[0].fd = 0;
  fds[1].fd = sock_fd;
  fds[0].events = POLLIN | POLLPRI;
  fds[1].events = POLLIN | POLLPRI;
  //srand(time(NULL));
  //fds[2].fd = 1 + rand() % 100;

  /* Normally we'd check an exit condition, but for this example
   * we loop endlessly.
   */
  printf("\nInformar texto de no maximo %d caracteres!!\n", TAM_TEXTO-10);
  while (1){
    /* Call poll() */
    ret = poll(fds, 2, -1);

    if (ret < 0){
      printf("Error - poll returned error: %s\n", strerror(errno));
      break;
    }
    if (ret > 0){

      /* Regardless of requested events, poll() can always return these */
      if (fds[0].revents & (POLLERR | POLLHUP | POLLNVAL)){
        printf("Error - poll indicated stdin error\n");
        break;
      }
      if (fds[1].revents & (POLLERR | POLLHUP | POLLNVAL)){
        printf("Error - poll indicated socket error\n");
        break;
      }

      /* Check if data to read from stdin */
      if (fds[0].revents & (POLLIN | POLLPRI)){
        bytes = read(0, texto, sizeof(texto));
        if (bytes < 0){
          printf("Error - stdin error: %s\n", strerror(errno));
          break;
        }
        printf("Texto informado pelo usuario: %.*s", (int)bytes, texto);
        cif_ou_dec = 1;
        extender_chave(key_letra, chave_extendida, texto_cifrado, texto,
                       texto_decifrado, vigenere_matrix,
                       ((int)bytes) - 1, TAM_CHAVE, cif_ou_dec);

        printf("Texto cifrado/enviado: %.*s\n", (int)bytes, texto_cifrado);
        //printf("Tam: %d\n", ((int)bytes)-1);

        bytes = sendto(sock_fd, texto_cifrado, bytes, 0,
                       (struct sockaddr *)peer, sizeof(struct sockaddr_in));
        if (bytes < 0){
          printf("Error - sendto error: %s\n", strerror(errno));
          break;
        }
      }

      /* Check if data to read from socket */
      if (fds[1].revents & (POLLIN | POLLPRI)){
        bytes = recvfrom(sock_fd, input_buffer, sizeof(input_buffer),
                         0, NULL, NULL);
        if (bytes < 0){
          printf("Error - recvfrom error: %s\n", strerror(errno));
          break;
        }

        printf("Texto cifrado/recebido: %.*s\n", ((int)bytes)-1, input_buffer);

        /*###Chamada de funcoes para limpar os vetores###*/
        inicializa_vetores(chave_extendida, TAM_TEXTO);
        inicializa_vetores(texto_cifrado, TAM_TEXTO);
        inicializa_vetores(texto_decifrado, TAM_TEXTO);
        inicializa_vetores(texto, TAM_TEXTO);
        /*###############################################*/

        cif_ou_dec = 2;
        extender_chave(key_letra, chave_extendida, input_buffer, texto,
                       texto_decifrado, vigenere_matrix,
                       ((int)bytes) - 1, TAM_CHAVE, cif_ou_dec);
        if (bytes > 0){
          printf("Texto decifrado: %.*s\n", ((int)bytes)-1, texto_decifrado);
          //printf("Tam2: %d\n", fds[2].fd);
        }
      }
    }
  }
}
int compute(int a, int m, int n){
  int r;
  int y = 1;

  while (m > 0){
    r = m % 2;

    // expon�ncia r�pida
    if (r == 1){
      y = (y * a) % n;
    }
    a = a * a % n;
    m = m / 2;
  }
  return y;

}
int sorteia_chave(){
  int key_letra = 0;
  int p = 23; // m�dulo
  int g = 5;  // base
  int a, b; // `a` � chave secreta de Alice, `b` � chave secreta de Bob.
  int A, B; // `A` � chave p�blica de Alice, `B` � chave p�blica de Bob

  srand(time(NULL));
  a = 115; // escolhe um inteiro secreto para a chave privada de Alice (conhecida apenas por Alice)
  // a = 1 + rand() % 100000;
  A = compute(g, a, p); // Calcula a chave p�blica de Alice (Alice enviar� `A` para Bob)
  b = 115;              // escolha um inteiro secreto para a chave privada de Bob (conhecida apenas por Bob)
  // b = 1 + rand() % 100000;
  B = compute(g, b, p); // Calcula a chave p�blica de Bob (Bob enviar� `B` para Alice)
  // Alice e Bob trocam suas chaves p�blicas `A` e `B` entre si
  // Encontra a chave secreta
  int keyA = compute(B, a, p);
  int keyB = compute(A, b, p);
  // printf("Alice's secret key is %d\nBob's secret key is %d\n", keyA, keyB);

  key_letra = sorteia_nova_chave(keyA);

  return key_letra;

}
int sorteia_nova_chave(int chave){
  int nova_chave = chave;
  while(1){
    if (nova_chave <= 96){
      nova_chave += 10;

    }
    if (nova_chave >= 123){
      nova_chave -= 10;

    }
    if ((nova_chave >= 97) && (nova_chave <= 122)){
      break;

    }
  }
  return nova_chave;

}
void inicializa_vetores(char vetor[], int tamanho){
  int i = 0;
  for (i = 0; i < tamanho; i++){
    vetor[i] = ' ';

  }
}
void mostrar_vetores(char vetor[], int tamanho){
  int i;
  for (i = 0; i < tamanho; i++){
    if (vetor[i] != ' '){
      printf("%c", vetor[i]);

    }
  }
  printf("\n");

}
void mostrar_matrix(char vigenere_matrix[TAM_MATRIX][TAM_MATRIX]){
  int i, j;
  printf("MATRIX \n");
  for (i = 0; i < (TAM_MATRIX - 1); i++){
    for (j = 0; j < (TAM_MATRIX - 1); j++){
      printf("%c ", vigenere_matrix[i][j]);

    }
    printf("\n");

  }
  printf("\n\n");

}
void extender_chave(char chave[TAM_CHAVE], char chave_extendida[TAM_TEXTO],
                    char texto_cifrado[TAM_TEXTO], char texto[TAM_TEXTO],
                    char texto_decifrado[TAM_TEXTO], char matrix[TAM_MATRIX][TAM_MATRIX],
                    int tam_texto, int tam_chave, int cif_ou_dec){
  int i = 0, aux = 0, j = 0, cont = 0;

  while (i < tam_texto){
    chave_extendida[i] = chave[0];
    i++;
  }
  if (cif_ou_dec == 1){
    cifrador_texto(texto, chave_extendida, texto_cifrado, matrix, tam_texto);

  } else {
    descifrador_texto(texto_decifrado, chave_extendida, texto_cifrado, matrix, tam_texto);
  
  }
}
void cifrador_texto(char texto[TAM_TEXTO], char chave_extendida[TAM_TEXTO],
                    char texto_cifrado[TAM_TEXTO], char matrix[TAM_MATRIX][TAM_MATRIX],
                    int tam_texto){
  int i = 0, j = 0, aux = 0, aux_i = 0, aux_j = 0;

  while (aux < tam_texto){
    aux_i = 0;
    aux_j = 0;
    for (i = 0; i < TAM_MATRIX; i++){
      for (j = 0; j < TAM_MATRIX; j++){
        if (matrix[0][j] == texto[aux]){
          aux_j = j;
          i = TAM_MATRIX;
          j = TAM_MATRIX;

        }
        if ((texto[aux] == 32)||(texto[aux] == '\0')){
          texto_cifrado[aux] = '#';
          j = 0;
          aux++;

        }
        if (texto[tam_texto] == ' '){
          printf("AQUI\n");

        }
      }
    }
    for (i = 0; i < TAM_MATRIX; i++){
      for (j = 0; j < TAM_MATRIX; j++){
        if (matrix[i][0] == chave_extendida[aux]){
          aux_i = i;
          i = TAM_MATRIX;
          j = TAM_MATRIX;
          texto_cifrado[aux] = matrix[aux_i][aux_j];
          aux++;

        }
      }
    }
  }
}
void descifrador_texto(char texto[TAM_TEXTO], char chave_extendida[TAM_CHAVE],
                       char texto_cifrado[TAM_TEXTO], char matrix[TAM_MATRIX][TAM_MATRIX],
                       int tam_texto){
  int i = 0, j = 0, aux = 0, aux_i = 0, aux_j = 0;

  while (aux < tam_texto){
    aux_i = 0;
    aux_j = 0;
    for (i = 0; i < TAM_MATRIX; i++){
      for (j = 1; j < TAM_MATRIX; j++){
        if (matrix[i][0] == chave_extendida[aux]){
          aux_i = i;
          i = TAM_MATRIX;
          j = TAM_MATRIX;

        }
      }
    }
    for (i = 1; i < TAM_MATRIX; i++){
      for (j = 1; j < TAM_MATRIX; j++){
        if ('#' == texto_cifrado[aux]){
          texto[aux] = ' ';
          aux++;

        }
        if (matrix[aux_i][j] == texto_cifrado[aux]){
          aux_j = j;
          i = TAM_MATRIX;
          j = TAM_MATRIX;
          texto[aux] = matrix[0][aux_j];
          aux++;

        }
      }
    }
  }
}
int tam_vet(char vetor[]){
  int i = 0, cont = 0;

  while (vetor[i] != '\0'){
    i++;

  }
  return i;

}
