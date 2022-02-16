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
            <a href="python.php" id="lingpython">Python</a>
            <a href="cobol.php" id="lingcobol">Cobol</a>
            <a href="html.php" id="linghtml">HTML</a>
            <a href="php.php" id="lingphp" style="color: orange;">PHP</a>
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
                    O for é a estrutura de repetição do PHP que utilizamos quando 
                    sabemos a quantidade de repetições que devem ser executadas.    
                </p>
                <h3>Exemplo de Codigo:</h3>
                <pre>
                    for ($i=0; $i < 10; $i++) {
                        echo $i."";
                    }
                </pre>
                <br /><br /><br />
                <h2>Comando "While".</h2>
                <p>
                    O while é a estrutura de repetição mais simples do PHP. 
                    Com ele informamos que um bloco de código deve ser repetido 
                    enquanto a condição declarada for verdadeira.
                </p>
                <h3>Exemplo de Codigo:</h3>
                <pre>
                    $i = 1;
                    while ($i <= 10) {
                        echo $i;
                        $i++;
                    }
                </pre>
                <br /><br /><br />
                <h2>Comando "do While".</h2>
                <p>
                    O loop do-while tem comportamento parecido com o while, 
                    diferenciando-se somente na validação do loop, 
                    que é feita no final de cada iteração.
                </p>
                <h3>Exemplo de Codigo:</h3>
                <pre>
                    $i = 1;
                    do {
                        echo $i;
                        $i++;
                    } while ($i < 11);
                </pre>
                <br /><br /><br />
                <h2>Comando "Foreach".</h2>
                <p>
                    O foreach é uma simplificação do operador FOR para se trabalhar em 
                    coleções de dados, ou seja, vetores e matrizes. Ele permite acessar cada
                    elemento individualmente iterando sobre toda a coleção
                    e sem a necessidade de informação de índices.
                </p>
                <h3>Exemplo de Codigo:</h3>
                <pre>
                    $vetor = array(1, 2, 3, 4, 5);
                    foreach($vetor as $item)
                    {
                        echo $item;
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