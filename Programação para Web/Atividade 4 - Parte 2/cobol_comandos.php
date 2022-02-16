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
                    <h2>A lingaguem provê a maioria dos
                        tipos de comandos, exceto o comando skip. Exemplos:</h2><br/>
                    
                    <h3>1º) Comando de atribuição:</h3>
                    move 31 to diasmes

                    <h3>2º) Chamada de procedimento</h3>
                    PERFORM P1000-INICIAL THRU P1000-FIM

                    <h3>3º) Comando seqüenciais:</h3>
                    DISPLAY “hello world!”<br/>
                    STOP “teste.”.

                    <h3>O comando acima pode ser escrito seqüencialmente:</h3>
                    DISPLAY “hello world!” STOP “teste.”.

                    <h3>4º) Comandos condicionais:</h3>
                    <pre>
                    4.1 – If
                    IF WSS-RESTO EQUAL 0 OR 1
                    MOVE ZEROES TO WSS-NUMERO-T (15)
                    ELSE
                    SUBTRACT WSS-RESTO FROM 11 GIVING WSS-NUMERO-T (15)
                    END-IF.
                    </pre>
                    <h3>4.2 – Evaluate ( case do Cobol):</h3>
                    <pre>
                    EVALUATE TRUE
                    WHEN LKS-ACAO = ‘C’
                    EVALUATE LKS-TIPO-CALCULO
                    WHEN ‘CPF’
                    MOVE LKS-NUMERO-I (07:09) TO WSS-NUMERO (05:09)
                    WHEN ‘CGC’
                    MOVE LKS-NUMERO-I (03:13) TO WSS-NUMERO (01:13)
                    WHEN ‘PIS’
                    MOVE LKS-NUMERO-I (06:10) TO WSS-NUMERO (05:10)
                    WHEN OTHER
                    MOVE 1 TO LKS-RETORNO
                    GOBACK
                    END-EVALUATE
                    WHEN LKS-ACAO = ‘V’
                    EVALUATE LKS-TIPO-CALCULO
                    WHEN ‘CPF’
                    WHEN ‘CGC’
                    WHEN ‘PIS’
                    MOVE LKS-NUMERO-I TO WSS-NUMERO
                    WHEN OTHER
                    MOVE 1 TO LKS-RETORNO
                    GOBACK
                    END-EVALUATE
                    WHEN OTHER
                    MOVE 2 TO LKS-RETORNO
                    GOBACK
                    END-EVALUATE.
                    </pre>
                    <h3>5º) Comando de iteração</h3>
                    <h3>5.1) indefinido pré-teste:</h3>
                    <pre>
                    PERFORM UNTIL WS-INDICE > 13
                    MOVE WS-INDICE TO NUM-LINHA(WS-INDICE)
                    MOVE SPACES TO TEXTO-LINHA(WS-INDICE)
                    ADD 1 TO WS-INDICE
                    END-PERFORM.
                    </pre>
                    <h3>5.2) definido:</h3>
                    <pre>
                    PERFORM VARYING CONTADOR FROM 1 BY 1
                    UNTIL CONTADOR > 10
                    DISPLAY “CONTADOR: ” CONTADOR
                    END-PERFORM.
                    </pre>
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