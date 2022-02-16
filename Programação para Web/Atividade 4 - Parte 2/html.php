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
            <a href="html.php" id="linghtml" style="color: orange;">HTML</a>
            <a href="php.php" id="lingphp">PHP</a>
        </div>
        <div id="principal">
            <?php include "menu_lateral.inc"; ?>
            <!--
            <div id="menu-esquerdo">
                <ul>
                    <li>
                        <a href="#" onclick="valida(1);" style="color: orange;">Introdução</a>
                    </li>
                    <li>
                        <a href="#" onclick="valida(2);">Comandos Básicos</a>
                    </li>
                    <li>
                        <a href="#" onclick="valida(3);">Estruturas de Repetição</a>
                    </li>
                </ul>
            </div>
        -->
            <div id="conteudo">
                <h1>Intodução às Linguagens de Marcação HTML</h1>
                <p>
                    Em sua essência, HTML é uma linguagem bastante simples composta
                    de elementos, que podem ser aplicados a pedaços de texto para dar-lhes
                    significado diferente em um documento (é um parágrafo? 
                    é uma lista de seleção? é parte de uma tabela?), estrutura um documento
                    em seções lógicas (Possui um cabeçalho? Três colunas de conteúdo?
                    Um menu de navegação?) e incorpora conteúdo como imagens e vídeos em
                    uma página. Este módulo irá introduzir os dois primeiros e apresentar 
                    conceitos fundamentais e a sintaxe que você precisa saber para entender
                    o HTML.
                </p>
                <p>
                    <a href="https://developer.mozilla.org/pt-BR/docs/Web/HTML" target="_blank">Documentação Completa</a>
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