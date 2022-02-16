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
            <a href="c.php" id="lingc">C</a>
            <a href="python.php" id="lingpython">Python</a>
            <a href="cobol.php" id="lingcobol" style="color: orange;">Cobol</a>
            <a href="html.php" id="linghtml">HTML</a>
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
                <h1>Intodução às Linguagens de Programação Cobol</h1>
                <p>
                    COBOL é uma das primeiras linguagens de programação de alto nível disseminada no mundo do
                    Processamento de Dados.
                    Nasceu, graças a iniciativa do Departamento de Defesa Norte-Americano, que presenteou o mundo com
                    esta linguagem fantástica.
                    Sua primeira versão foi lançada em 1961.
                    Há, com certeza, um exército de pessoas desejando a morte do COBOL.
                </p>
                <p>
                    <a href="https://www.ibm.com/support/pages/enterprise-cobol-zos-documentation-library" target="_blank">Documentação Completa</a>
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