<!DOCTYPE html>
<html>
<head>
    <title>Validação</title>
</head>
<body>
<?php
    echo "<link rel='stylesheet' href='style.css'>";

    $doc = new DOMDocument();
    $doc->load('GioMovies.xml');
    $topic = $doc->getElementsByTagName("topic");

    if($doc->validate()){
        echo "<h4> Documento validado com DTD! </h4>";

    }else{
        echo "<h4> Documento não validado com DTD! </h4>";

    }
    if($doc->schemaValidate("GioMovies.xsd")){
        echo "<h4> Documento validado com XML Schema! </h4>";

    }else{
        echo "<h4> Documento não validado com XML Schema! </h4>";
        
    }

    echo "
    <table border='1' class='tabelaIndex'>
    <tr>
    <th>Titulo</th>
    </tr>";
    echo "<tr>";
    foreach ($topic as $topics){
        $titulo = $topics->getElementsByTagName("baseNameString")->item(0)->nodeValue;
        echo "<td>$titulo</td>";
        echo "</tr>";

    }
    echo "</table>";
        
?>
</body>
</html>