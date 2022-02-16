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
                        <a href="#" onclick="valida(2);" style="color: orange;">Comandos Básicos</a>
                    </li>
                    <li>
                        <a href="#" onclick="valida(3);">Estruturas de Repetição</a>
                    </li>
                </ul>
            </div>
        -->
            <div id="conteudo">
                <h1>Comandos Basicos</h1>
                <p>
                    <iframe width="560" height="315" src="https://www.youtube.com/embed/PJnJQ2qtrv0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
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