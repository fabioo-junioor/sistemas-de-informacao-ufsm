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
                <h1>Intodução às Linguagens de Programação C</h1>
                <p>
                    É uma linguagem de programação compilada de propósito geral, estruturada,
                    imperativa, procedural, padronizada pela Organização Internacional para Padronização (ISO),
                    criada em 1972 por Dennis Ritchie na empresa AT&T Bell Labs para desenvolvimento do sistema
                    operacional
                    Unix (originalmente escrito em Assembly). C é uma das linguagens de programação mais populares
                    e existem poucas arquiteturas para as quais não existem compiladores para C. C tem influenciado
                    muitas outras linguagens de programação (por exemplo, a linguagem Java), mais notavelmente
                    C++, que originalmente começou como uma extensão para C.
                </p>
                <p>
                    Um programa em C é composto por um conjunto de Funções. A função pela qual o programa começa a ser
                    executado chama-se main.
                    Após cada cada comando em C deve-se colocar um ; (ponto-e-vírgula).
                    Um programa em C deve ser Identado para que possa ser lido com mais facilidade.
                </p>
                <p>
                    <a href="https://docs.microsoft.com/pt-br/cpp/c-language/c-language-reference?view=msvc-170" target="_blank">Documentação Completa</a>
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