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
                <pre>
                    <h2>Comandos de saída padrão:</h2>
                    print()
                        Pula para a próxima linha
                    print(expressão)
                        Escreve o resultado da expressão
                        Pula para a próxima linha
                    print(expressão1,…,expressãoN)
                        Escreve o resultado de cada expressão
                        Espaço em branco é escrito entre cada par de expressão
                        Pula para a próxima linha
                    print(expressão,end=término)
                        Escreve o resultado da expressão
                        Ao final, escreve o String de término
                    print(expressão1, …, expressãoN,end=término)
                        Escreve o resultado de cada expressão
                        Espaço em branco é escrito entre cada par de expressão
                        Ao final, escreve o String de término
                    
                    <h2>Expressões Formatadas (operador %(…)):</h2>
                    Sintaxe da expressão formatada:
                        texto = “…%formato1 … %formatoN…” %(exp1, …, expN)
                    Formatos mais comuns:
                        d (inteiro), f (número com ponto flutuante) e s (String)
                    
                    Exemplos:
                    msg = " A media dos numeros é %4.2f" %(8656656.6164134)
                    print(msg)

                    print("%f + %f = %4.1f" %(15, 9.578421, 15+9.578421 ))

                    print("%d + %d = %d" %(5, 7.578421, 5+7.578421 ), end="!!!")
                    
                    <h2>Comandos de entrada padrão:</h2>
                    input()
                        Comando que aguarda o usuário fornecer um valor
                        expresso por uma sequencia de caracteres.
                        Este comando suspende a execução do programa até
                        que o usuário escreva sua entrada e precione enter.
                    input(mensagem)
                        Comando que escreve a expressão mensagem e aguarda
                        o usuário fornecer um valor expresso por uma 
                        sequencia de caracteres.
                        Este comando suspende a execução do programa até que
                        o usuário escreva sua entrada e precione enter.
                </pre>
            </div>
        </div>
        <div id="rodape">
            Curso de Programacao Web 01-2020
        </div>
    </div>
    <script src="js/index.js"></script>
</body>

</html>