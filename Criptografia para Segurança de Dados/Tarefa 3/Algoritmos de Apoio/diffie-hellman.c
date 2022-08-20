#include <stdio.h>
#include <time.h>

// Função para calcular `a^m mod n`
int compute(int a, int m, int n)
{
    int r;
    int y = 1;
 
    while (m > 0)
    {
        r = m % 2;
 
        //exponência rápida
        if (r == 1) {
            y = (y*a) % n;
        }
        a = a*a % n;
        m = m / 2;
    }
 
    return y;
}
int sorteia_nova_chave(int chave){
	int nova_chave = chave;
	while(1){
    	if(nova_chave <= 96){
    		nova_chave += 10;
    		
		}
		if(nova_chave >= 123){
    		nova_chave -= 10;
    		
		}
		if((nova_chave >= 97) && (nova_chave <= 122)){
    		break;
    		
		}
	}
	
		return nova_chave;
		
}
 
// Programa em C para demonstrar o algoritmo Diffie-Hellman
int main()
{
    int p = 23;        // módulo
    int g = 5;        //base
 
    int a, b;    // `a` – chave secreta de Alice, `b` – chave secreta de Bob.
    int A, B;    // `A` – chave pública de Alice, `B` – chave pública de Bob
    
    int key_aux;
 
 	srand(time(NULL));
 	
    // escolhe um inteiro secreto para a chave privada de Alice (conhecida apenas por Alice)
   	a = 1 + rand() % 100000;
    printf("a: %d \n", a);
 
    // Calcula a chave pública de Alice (Alice enviará `A` para Bob)
    A = compute(g, a, p);
 
    // escolha um inteiro secreto para a chave privada de Bob (conhecida apenas por Bob)
    b = 1 + rand() % 100000;
    printf("b: %d \n", b);
 
    // Calcula a chave pública de Bob (Bob enviará `B` para Alice)
    B = compute(g, b, p);
 
    // Alice e Bob trocam suas chaves públicas `A` e `B` entre si
 
    // Encontra a chave secreta
    int keyA = compute(B, a, p);
    int keyB = compute(A, b, p);
    
    key_aux = sorteia_nova_chave(keyA);
	
 
    printf("Alice's secret key is %d\nBob's secret key is %d\n", keyA, keyB);
    printf("Alice's secret key is %d\nBob's secret key is %c", key_aux, key_aux);
 
    return 0;
}
