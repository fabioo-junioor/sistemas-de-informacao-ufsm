//LINGUAGEM FUNCIONAL
//EXEMPLOS DE PASSAGEM DE PARAMETRO
//------------------------------------------
function funcao1 (num1, num2) {
    return num1 + num2;
    
}
console.log(funcao1(3,3))
//------------------------------------------

//------------------------------------------
function funcao2 (num1=2) {
    return num1 *2;
    
}
console.log(funcao2())
//------------------------------------------

//------------------------------------------
var array = [1,2,3,4,5,6]
function funcao3 (parametro) {
    return console.log(parametro);
    
}
funcao3(array)
//------------------------------------------

//------------------------------------------
const obj = {
    nome: "fabio",
    sobrenome: "junior",
    idade: 29,
    faculdade: "SI",
    semestre: 4
}
function funcao4 (parametro) {
    return console.log(parametro);

}
funcao4(obj)
//------------------------------------------

//------------------------------------------
function funcao5 (parametro){
    return parametro;

}
function auxiliar () {
    return console.log("RETURN FUNC AUX");

}
funcao5(auxiliar())
//------------------------------------------