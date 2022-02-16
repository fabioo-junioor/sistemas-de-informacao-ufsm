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
            <a href="index.php"><img src="img/home.png" alt="home" id="home"
                onmouseover="this.src='img/homeg.png';" onmouseout="this.src='img/home.png';"></a>
            <a href="c.php" id="lingc">C</a>
            <a href="python.php" id="lingpython" style="color: orange;">Python</a>
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
                <p>
                    A estrutura de repetição for permite executar um bloco de códigos repetidas
                    vezes até que uma condição seja verdadeira. Na linguagem Python, 
                    ela é utilizada para percorrer elementos em sequência, como uma string, 
                    uma lista, uma tupla ou objetos iteráveis.    
                </p>
                <h3>Exemplo de Codigo:</h3>
                <pre>
                    nomes = ['Pedro', 'João', 'Leticia']
                    for n in nomes:
                        print(n)
                </pre>
                <br /><br /><br />
                <h2>Comando "While-else".</h2>
                <p>
                    Ao final do while podemos utilizar a instrução else. 
                    O propósito disso é executar alguma instrução ou bloco de código ao final
                    do loop.
                </p>
                <h3>Exemplo de Codigo:</h3>
                <pre>
                    contador = 0
                    while (contador < 5):
                          print(contador)
                          contador = contador + 1
                    else:
                          print("O loop while foi encerrado com sucesso!")
                </pre>
                <br /><br /><br />
                <h2>Comando "While".</h2>
                <p>
                    O comando while faz com que um conjunto de instruções seja executado
                    enquanto uma condição é atendida. Quando o resultado dessa condição passa
                    a ser falso, a execução do loop é interrompida.
                </p>
                <h3>Exemplo de Codigo:</h3>
                <pre>
                    contador = 0
                    while (contador < 5):
                           print(contador)
                           contador   = contador + 1
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