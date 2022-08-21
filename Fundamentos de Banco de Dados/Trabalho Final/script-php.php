<?php
$con1 = mysqli_connect('localhost', 'root', '', 'csv_11');
$sql1 = "select * from formulario";
$res1 = mysqli_query($con1,$sql1);

while($registro1 = mysqli_fetch_array($res1)){
    $email = $registro1['COL2'];
    $nome = $registro1['COL3'];
    $idade = $registro1['COL4'];
    $estudante = $registro1['COL5'];

    $diaUm = $registro1['COL6'];
    $diaDois = $registro1['COL7'];
    $diaTres = $registro1['COL8'];
    $diaQuatro = $registro1['COL9'];

    $NotaDiaUm = $registro1['COL10'];
    $NotaDiaDois = $registro1['COL11'];
    $NotaDiaTres = $registro1['COL12'];
    $NotaDiaQuatro = $registro1['COL13'];

    $recomendacao = $registro1['COL14'];
    $nomeMidias = $registro1['COL15'];

    
    if($estudante == 'Ensino Superior'){
        $con2 = mysqli_connect('localhost', 'root', '', 'pesquisa1');
        $sql2 = "insert into usuario values";
        $sql2 .= "(NULL,'$nome','$email','$idade', 3)";
        mysqli_query($con2,$sql2);
        //mysqli_close($con2);
        
    }else if($estudante == 'Ensino Medio'){
        $con2 = mysqli_connect('localhost', 'root', '', 'pesquisa1');
        $sql2 = "insert into usuario values";
        $sql2 .= "(NULL,'$nome','$email','$idade', 2)";
        mysqli_query($con2,$sql2);
        //mysqli_close($con2);

    }else if($estudante == 'Ensino Fundamental'){
        $con2 = mysqli_connect('localhost', 'root', '', 'pesquisa1');
        $sql2 = "insert into usuario values";
        $sql2 .= "(NULL,'$nome','$email','$idade', 1)";
        mysqli_query($con2,$sql2);
        //mysqli_close($con2);

    }else if($estudante == 'Pos Graduacao'){
        $con2 = mysqli_connect('localhost', 'root', '', 'pesquisa1');
        $sql2 = "insert into usuario values";
        $sql2 .= "(NULL,'$nome','$email','$idade', 4)";
        mysqli_query($con2,$sql2);
        //mysqli_close($con2);

    }else if($estudante == 'Nao sou estudante'){
        $con2 = mysqli_connect('localhost', 'root', '', 'pesquisa1');
        $sql2 = "insert into usuario values";
        $sql2 .= "(NULL,'$nome','$email','$idade', 5)";
        mysqli_query($con2,$sql2);
        //mysqli_close($con2);

    }

    $con2 = mysqli_connect('localhost', 'root', '', 'pesquisa1');
    $sql2 = "insert into evento values";
    $sql2 .= "(NULL,'$diaUm','$diaDois', '$diaTres','$diaQuatro','$NotaDiaUm',
    '$NotaDiaDois','$NotaDiaTres','$NotaDiaQuatro','$recomendacao','$nomeMidias')";
    mysqli_query($con2,$sql2);
    //mysqli_close($con2);    

}
$con1 = mysqli_connect('localhost', 'root', '', 'pesquisa1');
$sql1 = "select * from usuario";
$res1 = mysqli_query($con1,$sql1);

while($registro1 = mysqli_fetch_array($res1)){
    $idUser = $registro1['idUsuario'];
    
    $con2 = mysqli_connect('localhost', 'root', '', 'pesquisa1');
    $sql2 = "insert into participacao values";
    $sql2 .= "((NULL),
    (select idEvento from evento where idEvento = '$idUser'),
    (select idUsuario from usuario where idUsuario = '$idUser'))";
    mysqli_query($con2,$sql2);
    mysqli_close($con2);    
   
}
?>