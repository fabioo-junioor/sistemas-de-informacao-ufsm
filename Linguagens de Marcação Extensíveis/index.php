<!DOCTYPE html>
<html>
<head>
    <title>Transformação</title>
</head>
<body>
<?php
    echo "<link rel='stylesheet' href='style.css'>";

    $xml = simplexml_load_file('GioMovies.xml');

    echo "<div class='corpo'>";
    echo "<div class='conteudo'>";

    if(isset($_GET['filme'])){
        apresenta_conteudo($_GET['filme']);

    }
    echo "</div>";
    echo "<div class='conteudo'>";
    echo "
        <table border='1' class='tabelaIndex'>
        <tr>
        <th>Lista de Filmes</th>
        </tr>";
    echo "<tr>";
    
    foreach($xml->topic as $topics){
        if(isset($topics->instanceOf)){
            if($topics->instanceOf->topicRef->attributes() == "#Filme"){
                echo "<td><a href='index.php?filme=".$topics->baseName->baseNameString."'>".$topics->baseName->baseNameString."</a></td>";
                echo "</tr>";
            
            }
        }
    }       
    echo "</table>";
    echo "</div>";
    echo "</div>";

    function apresenta_conteudo($filme){
        global $xml;
        echo "
        <table border='1' class='tabelaIndex'>
        <tr>
        <th>Nome Filme</th>
        </tr>";
        echo "<tr>";
        echo "<td>$filme</td>";
        echo "<tr>";
        foreach($xml->topic as $topics){
            if($filme == $topics->baseName->baseNameString){
                foreach($topics->occurrence as $occur){
                    if(isset($occur->scope)){
                        echo "<th>".remove_caracteres($occur->scope->topicRef->attributes())."</th>";
                        echo "</tr><tr>";
                        echo "<td>".$occur->resourceData."</td>";
                        echo "</tr><tr>";
                        
                    }else if(isset($occur->instanceOf)){
                        echo "<th>".remove_caracteres($occur->instanceOf->topicRef->attributes())."</th>";
                        echo "</tr><tr>";
                        echo "<td>".$occur->resourceRef->attributes()."</td>";
                        echo "</tr><tr>";

                    }
                }
            }
        }
        foreach($xml->association as $ass){
            if(remove_caracteres(strtolower(remove_caracteres_especiais($filme))) == remove_caracteres($ass->member[0]->topicRef->attributes())){
                if(isset($ass)){
                    echo "<th>".remove_caracteres($ass->instanceOf->topicRef->attributes())."</th>";
                    echo "</tr><tr>";
                    echo "<td>".remove_caracteres($ass->member[1]->topicRef->attributes())."</td>";
                    echo "</tr><tr>";
                    
                }
            }
        }
        echo "</tr>";
        echo "</table>";
        
    }
    function remove_caracteres($string){
        $result = str_replace(array("-","_","#","id"), ' ', $string);
        return trim($result, ' ');

    }
    function remove_caracteres_especiais($string){
        $nova_string = preg_replace(array("/(á|à|ã|â|ä)/","/(Á|À|Ã|Â|Ä)/","/(é|è|ê|ë)/","/(É|È|Ê|Ë)/","/(í|ì|î|ï)/","/(Í|Ì|Î|Ï)/","/(ó|ò|õ|ô|ö)/","/(Ó|Ò|Õ|Ô|Ö)/","/(ú|ù|û|ü)/","/(Ú|Ù|Û|Ü)/","/(ñ)/","/(Ñ)/"),explode(" ","a A e E i I o O u U n N"),$string);
        return $nova_string;

    }  
    
?>
</body>