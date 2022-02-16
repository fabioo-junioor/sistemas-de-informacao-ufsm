<html>

<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>Site das Linguagens de Programação</title>
    <link rel="stylesheet" type="text/css" href="css/cssdiv.css" />
</head>

<body>
    <div id="estrutura">
        <div id="cabecalho">
            <div id="titulo-cabecalho">
                <h1> Linguagens de Programação (e Marcação)</h1>
            </div>
        </div>
        <div id="menu-superior">
            <a href="index.php"><img src="img/home.png" alt="home" id="home" onmouseover="this.src='img/homeg.png';"
                    onmouseout="this.src='img/home.png';"></a>
            <a href="c.php" id="lingc" style="color: orange;">C</a>
            <a href="python.php" id="lingpython">Python</a>
            <a href="cobol.php" id="lingcobol">Cobol</a>
            <a href="html.php" id="linghtml">HTML</a>
            <a href="php.php" id="lingphp">PHP</a>
        </div>
        <div id="principal">
            <?php include "menu_lateral.inc"; ?>
            <!--
            <div id="menu-esquerdo">
                <ul>
                    <li>
                        <a href="#" onclick="valida(1);">Introdução</a>
                    </li>
                    <li>
                        <a href="#" onclick="valida(2);">Comandos Básicos</a>
                    </li>
                    <li>
                        <a href="#" onclick="valida(3);" style="color: orange;">Estruturas de Repetição</a>
                    </li>
                </ul>
            </div>
        -->
            <div id="conteudo">
                <h1>Estruturas de Repetição</h1>
                <h2>Comando "for".</h2>
                <p>O laço for é uma estrutura de repetição muito utilizada nos programas em C.
                    É muito útil quando se sabe de antemão quantas vezes a repetição
                    deverá ser executada. Este laço utiliza uma variável para controlar a contagem
                    do loop, bem como seu incremento. Trata-se de um comando bem enxuto,
                    já que própria estrutura faz a inicialização, incremento e encerramento do laço.
                </p>
                <h3>Exemplo de Codigo:</h3>
                <pre>
                    //Exemplo1: Programa usando loop for em C
                    #include <stdio.h>
                    #include <conio.h>
                    int main(void){
	                    int contador; //variável de controle do loop
                        for(contador = 1; contador <= 10; contador++){
		                    printf("%d ", contador);
                        }
	                    getch();
	                    return(0);
                    }
                </pre>
                <br /><br /><br />
                <h2>Comando "do While".</h2>
                <p>
                    Esta estrutura de repetição, garante que o bloco de instruções seja executado
                    no mínimo uma vez, já que a condição que controla o laço é testada apenas no final do comando.
                    A diferença entre o comando while e o do…while é justamente o local onde a condição
                    que controla o laço é testada. No comando while a condição é testada antes do bloco
                    de instruções, e caso a condição seja falsa a repetição não será executada.
                    No do…while o bloco de comandos é executado pelo menos uma vez de forma obrigatória,
                    independente do resultado da expressão lógica.
                </p>
                <h3>Exemplo de Codigo:</h3>
                <pre>
                    #include<stdio.h>
                        int main(void)
                        {
                          float nota1=0,nota2=0,media=0;
                          int resp;
                          
                          do
                          {
                            printf("Digite a primeira nota: ");
                            scanf("%f",&nota1);
                            printf("Digite a segunda nota: ");
                            scanf("%f",&nota2);
                            
                            media = (nota1 + nota2)/2;
                            printf("Media do aluno = %f\n",media);
                            
                            printf("Digite 1 para continuar ou 2 para sair\n");
                            scanf("%d", &resp);
                          
                          }while (resp==1);
                          
                          return 0;
                        }
                </pre>
                <br /><br /><br />
                <h2>Comando "While".</h2>
                <p>
                    Lembrando que chamamos de variável de controle a variável testada na condição.
                    Para que seja possível fazer o teste, a variável de controle deve ter sido inicializada
                    previamente. Observe que o teste da condição ocorre no início do laço.
                    Enquanto a condição permanecer verdadeira, são executadas as instruções.
                    Quando a condição se tornar falsa, o processamento será desviado para fora do laço.
                </p>
                <h3>Exemplo de Codigo:</h3>
                <pre>
                    #include <stdio.h>
                        int main(void)
                        {
                          int contador = 1; //declarando e inicializando
                                            a variável de controle
                          
                          while (contador <= 10) // Testando a condição
                          {
                            printf("%d ", contador); //Executando um comando
                                                        dentro do laço
                            
                            contador++; //atualizando a variável de controle
                          }  
                          
                          return 0;
                        }
                </pre>
                <br /><br /><br />
            </div>
        </div>
        <div id="rodape">
            Curso de Programacao Web 01-2020
        </div>
    </div>
    <script src="js/index.js"></script>
</body>

</html>