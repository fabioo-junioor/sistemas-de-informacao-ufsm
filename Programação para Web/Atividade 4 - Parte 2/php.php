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
                <h1>Intodução às Linguagens de Programação PHP</h1>
                <p>
                    PHP é uma linguagem poderosa e um interpretador, seja incluído em um servidor
                    web como um módulo ou executado separadamente como binário CGI, 
                    é possível acessar arquivos, executar comandos e abrir conexões de rede no servidor.
                    Essas propriedades fazem qualquer coisa executando em um servidor web inseguras por padrão.
                    PHP é desenhado especificamente para ser uma linguagem mais segura para escrever 
                    programas CGI que Perl ou C, e com a escolha correta de opções de configuração em tempo compilação
                    ou de execução, e práticas corretas de programação, ela pode dar a combinação exata
                    de liberdade e segurança que você precisa.
                </p>
                <p>
                    Como existem diferentes maneiras de utilizar o PHP, existem várias opções
                    de configuração controlando seu comportamento. Um grande leque de opções 
                    garante que você pode usar o PHP para vários propósitos, 
                    mas também significa que existem combinações dessas opções e configurações
                    do servidor que resultam em uma instalação insegura.
                </p>
                <p>
                    A flexibilidade de configuração do PHP é comparável com a flexibilidade de código.
                    PHP pode ser usado para montar um servidor de aplicações completo, 
                    com todo o poder de um usuário shell, ou pode ser usado para inclusão simples de arquivos
                    no lado do servidor com pouco risco em um ambiente bem controlado. 
                    Como montar o ambiente, e o quão seguro ele é, depende muito do desenvolvedor.
                </p>
                <p>
                    <a href="https://www.php.net/" target="_blank">Documentação Completa</a>
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