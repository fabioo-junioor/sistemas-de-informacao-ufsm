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
            <a href="index.php" id="lingc">C</a>
            <a href="python.php" id="lingpython">Python</a>
            <a href="cobol.php" id="lingcobol">Cobol</a>
            <a href="html.php" id="linghtml" style="color: orange;">HTML</a>
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
                <p>
                    HTML é uma linguagem que não tem esse tipo de estrutura!!
                </p>
            </div>
        </div>
        <div id="rodape">
            Curso de Programacao Web 01-2020
        </div>
    </div>
    <script src="js/index.js"></script>
</body>
</html>