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
                <h1>Intodução às Linguagens de Programação Python</h1>
                <p>
                    Python é uma linguagem poderosa e divertida. Com ela você pode fazer diversas
                    coisas como:
                    Construção de sistemas Web com Django, Flask, Pyramid, etc.
                    Análise de dados, Inteligência Artificial, Machine Learning e etc com Numpy,
                    Pandas, Matplotlib, etc.
                    Construção de aplicativos com Kivy e Pybee
                    Construção de sistemas desktop com Tkinter, WxPython, etc.
                    Existem diversos cursos onlines onde você pode encontrar material. 
                    São cursos que você consegue aprender o básico da programação com Python como tipos
                    de variáveis, como escrever funções, etc. 
                    </p>
                    <p>
                        <a href="https://docs.python.org/3/" target="_blank">Documentação Completa</a>
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