<!DOCTYPE html>
<html>
<head>
    <title>Xquery</title>
</head>
<body>
<?php
    echo "<link rel='stylesheet' href='style.css'>";

    $xml = simplexml_load_file('GioMovies.xml');
   
    function consulta1($xml){
        $generos = array();
        foreach($xml->association as $ass){
            foreach($ass->instanceOf->topicRef->attributes() as $value){
                if($value == "#filme-genero"){
                    $generos[] = remove_caracteres($ass->member[1]->topicRef->attributes());
    
                }               
            }
        }
        $generos = array_unique($generos);
        echo "
            <table border='1' class='tabelaXquery'>
            <tr>
            <th>Quais são os tipos de gênero de filmes, sem repetição?</th>
            </tr>";
        echo "<tr>";
        foreach($generos as $genero){
            echo "<td>$genero</td>";
            echo "</tr>";
    
        }
        echo "</table>";

    }
    function consulta2($xml){
        $titulos = array();
        foreach($xml->association as $ass){
            foreach($ass->instanceOf->topicRef->attributes() as $value){
                if(($value == "#filme-ano") && (remove_caracteres($ass->member[1]->topicRef->attributes())) == "2000"){
                    $titulos[] = remove_caracteres($ass->member[0]->topicRef->attributes());
    
                }               
            }
        }
        asort($titulos);
        echo "
            <table border='1' class='tabelaXquery'>
            <tr>
            <th>Quais são os títulos dos filmes que foram produzidos em 2000, ordenados alfabeticamente?</th>
            </tr>";
        echo "<tr>";
        foreach($titulos as $titulo){
            echo "<td>$titulo</td>";
            echo "</tr>";
    
        }
        echo "</table>";

    }
    function consulta3($xml){
        $titulos = array();
        foreach($xml->topic as $topics){
            foreach($topics->occurrence as $occur){
                if(isset($occur->scope)){
                    if(($occur->scope->topicRef->attributes() == "#sinopse")
                        && (procurar_palavra($occur->resourceData, "especial"))){
                            
                            foreach($topics->occurrence as $occ){
                                if(isset($occ->scope)){
                                    if($occ->scope->topicRef->attributes() == "#ingles"){
                                        $titulos[] = $occ->resourceData;
                                }
                            }
                        }

                    }
                }
               
            }
        }        
        echo "
            <table border='1' class='tabelaXquery'>
            <tr>
            <th>Quais são os títulos em inglês dos filmes que tem a palavra “especial” na sinopse?</th>
            </tr>";
        echo "<tr>";
        foreach($titulos as $titulo){
            echo "<td>$titulo</td>";
            echo "</tr>";
    
        }
        echo "</table>";

    }
    function consulta4($xml){
        $titulos = array();
        foreach($xml->topic as $topics){
            foreach($xml->association as $ass){
                if(($ass->member[1]->topicRef->attributes() == "#thriller") && 
                (remove_caracteres($ass->member[0]->topicRef->attributes()) == (remove_caracteres($topics->attributes())))){
                    foreach($topics->occurrence as $occur){
                        if(isset($occur->resourceRef))
                            $titulos[] = $occur->resourceRef->attributes();
                        
                    }
                }              
            }
        }        
        echo "
            <table border='1' class='tabelaXquery'>
            <tr>
            <th>Quais são os sites dos filmes que são do tipo “thriller”?</th>
            </tr>";
        echo "<tr>";
        foreach($titulos as $titulo){
            echo "<td>$titulo</td>";
            echo "</tr>";
    
        }
        echo "</table>";

    }
    function consulta5($xml){
        $contFilme = 0;
        foreach($xml->topic as $topics){
            $contElenco = 0;
            foreach($topics->occurrence as $occur){
                if(isset($occur->scope)){
                    if($occur->scope->topicRef->attributes() == "#elencoApoio"){
                        $contElenco++;
                    
                    }
                }        
            }
            if($contElenco > 3){
                //echo $contElenco." - ", $topics->attributes() . "<br>";
                $contFilme++;

            }
        }        
        echo "
            <table border='1' class='tabelaXquery'>
            <tr>
            <th>Quantos filmes contém mais de 3 atores como elenco de apoio?</th>
            </tr>";
        echo "<tr>";
        echo "<td>$contFilme</td>";
        echo "</tr>";
        echo "</table>";

    }
    function consulta6($xml){
        $titulos = array();
        foreach($xml->topic as $topics){
            foreach($xml->association as $ass){
                  if((remove_caracteres($topics->attributes()) == remove_caracteres($ass->member[0]->topicRef->attributes())) &&
                        ($ass->instanceOf->topicRef->attributes() == "#filme-elenco")){
                            foreach($topics->occurrence as $occur){
                                if(isset($occur->scope)){
                                    if($occur->scope->topicRef->attributes() == "#sinopse"){
                                        if(procurar_palavra($occur->resourceData, remove_caracteres($ass->member[1]->topicRef->attributes()))){
                                            //echo $ass->member[1]->topicRef->attributes(). "<br>";
                                            //echo $occur->resourceData. "<br><br><br>";
                                            $titulos[] = $topics->attributes();
                                        
                                    }
                                }
                            }
                        }
                  }      
            }
        }
        $titulos = array_unique($titulos);
        echo "
            <table border='1' class='tabelaXquery'>
            <tr>
            <th>Quais são os ID dos filmes que tem o nome de algum membro do elenco citado na sinopse?</th>
            </tr>";
        echo "<tr>";
        foreach($titulos as $titulo){
            echo "<td>$titulo</td>";
            echo "</tr>";
    
        }
        echo "</table>";

    }
    function remove_caracteres($string){
        $result = str_replace(array("-","_","id","#"), ' ', $string);
        return trim($result, ' ');

    }
    function procurar_palavra($string, $palavra){   
        if(preg_match("/{$palavra}\b/i", $string)){
            return true;

        }else{
            return false;

        }
    }
    echo "<div class='corpoX'>";
        echo "<div class='conteudoX'>"; 
            consulta1($xml);
        echo "</div>";
        echo "<div class='conteudoX'>"; 
            consulta2($xml);
        echo "</div>";
        echo "<div class='conteudoX'>"; 
            consulta3($xml);
        echo "</div>";
        echo "<div class='conteudoX'>"; 
            consulta4($xml);
        echo "</div>";
        echo "<div class='conteudoX'>"; 
            consulta5($xml);
        echo "</div>";
        echo "<div class='conteudoX'>"; 
            consulta6($xml);
        echo "</div>";
    echo "</div>";

?>
</body>