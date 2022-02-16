console.log("OLLAA")

function valida(id = 1){
    let corMenuC = document.getElementById("lingc").style.color;
    let corMenuPython = document.getElementById("lingpython").style.color;
    let corMenuCobol = document.getElementById("lingcobol").style.color;
    let corMenuHtml = document.getElementById("linghtml").style.color;
    let corMenuPhp = document.getElementById("lingphp").style.color;
    
    if((corMenuC === "orange") && (id === 1)){
        window.location.href = "c.php";

    }else if((corMenuC === "orange") && (id === 2)){
        window.location.href = "c_comandos.php";

    }else if((corMenuC === "orange") && (id === 3)){
        window.location.href = "c_estrutura.php";

    }else if((corMenuPython === "orange") && (id === 1)){
        window.location.href = "python.php";

    }else if((corMenuPython === "orange") && (id === 2)){
        window.location.href = "python_comandos.php";

    }else if((corMenuPython === "orange") && (id === 3)){
        window.location.href = "python_estrutura.php";

    }else if((corMenuCobol === "orange") && (id === 1)){
        window.location.href = "cobol.php";

    }else if((corMenuCobol === "orange") && (id === 2)){
        window.location.href = "cobol_comandos.php";

    }else if((corMenuCobol === "orange") && (id === 3)){
        window.location.href = "cobol_estrutura.php";

    }else if((corMenuHtml === "orange") && (id === 1)){
        window.location.href = "html.php";

    }else if((corMenuHtml === "orange") && (id === 2)){
        window.location.href = "html_comandos.php";

    }else if((corMenuHtml === "orange") && (id === 3)){
        window.location.href = "html_estrutura.php";

    }else if((corMenuPhp === "orange") && (id === 1)){
        window.location.href = "php.php";

    }else if((corMenuPhp === "orange") && (id === 2)){
        window.location.href = "php_comandos.php";

    }else if((corMenuPhp === "orange") && (id === 3)){
        window.location.href = "php_estrutura.php";

    }else{
        window.location.href = "index.php";

    }    
}