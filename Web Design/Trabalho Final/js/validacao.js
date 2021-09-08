var btn = document.getElementById('enviar');

btn.onclick = function(){
    if(formulario.nome.value.length === 0){
        alert("O nome nao pode ser vazio!");
        formulario.nome.focus();
        return false;

    }else{
        if(formulario.nome.value.length < 6){
            alert("O nome dever ter no minimo 6 caracteres!");
            formulario.nome.focus();
            return false;

        }
    }
    if(formulario.email.value.length === 0){
        alert("O email nao pode ser vazio!");       
        formulario.email.focus();
        return false;

    }
    if(formulario.cidade.value.length === 0){
        alert("O cidade nao pode ser vazio!");
        formulario.cidade.focus();
        return false;

    }else{
        if(formulario.cidade.value.length < 4){
            alert("O nome da cidade dever ter no minimo 4 caracteres!");
            formulario.cidade.focus();
            return false;

        }
    }
    if(formulario.mensagem.value.length === 0){
        alert("A mensagem nao pode ser vazio!");
        formulario.mensagem.focus();
        return false;

    }
    if(isNaN(formulario.idade.value)){
        alert("A idade dever ser numero!");
        return false;
    }
}