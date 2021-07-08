-- Prática 01 de Haskell - Parte 2
-- Nome: Fabio Junior

import Arquivo

{-1 Crie uma função itemize :: [String] -> [String] que receba uma lista de nomes e aplique a função htmlItem em cada nome.-}
itemize :: [String] -> [String]
itemize n = map htmlItem n


{-2 Crie uma função onlyVowels :: String -> String que receba uma string e retorne outra contendo somente suas vogais. Por exemplo: onlyVowels "abracadabra" vai retornar "aaaaa".-}
onlyVowels :: String -> String
onlyVowels palavra = filter isVowel palavra


{-3 Escreva uma função onlyElderly :: [Int] -> [Int] que, dada uma lista de idades, selecione somente as que forem maiores que 65 anos.-}
onlyElderly :: [Int] -> [Int]
onlyElderly idade = filter isElderly idade


{-4 Crie uma função onlyLongWords :: [String] -> [String] que receba uma lista de strings e retorne somente as strings longas (use a função isLongWord definida no código de exemplo no início da prática).-}
onlyLongWords :: [String] -> [String]
onlyLongWords longas = filter isLongWord longas


{-5 Escreva uma função onlyEven que receba uma lista de números inteiros e retorne somente aqueles que forem pares. Agora é com você a definição da tipagem da função!-}
onlyEven :: [Int] -> [Int]
onlyEven pares = filter isEvenBetter pares


{-6 Escreva uma função onlyBetween60and80 que receba uma lista de números e retorne somente os que estiverem entre 60 e 80, inclusive. Você deverá criar uma função auxiliar between60and80 e usar && para expressar o operador "E" lógico em Haskell.-}
onlyBetween60and80 :: [Int] -> [Int]
onlyBetween60and80 idade = filter between idade


{-7 Crie uma função countSpaces que receba uma string e retorne o número de espaços nela contidos. Dica 1: você vai precisar de uma função que identifica espaços. Dica 2: aplique funções consecutivamente, isto é, use o resultado de uma função como argumento para outra.-}
countSpaces :: String -> Int
countSpaces espaco = length (filter noSpace espaco)


{-8 Escreva uma função calcAreas que, dada uma lista de valores de raios de círculos, retorne uma lista com a área correspondente a cada raio.-}
calcAreas :: [Float] -> [Float]
calcAreas raio = map circleArea raio


{-9 Neste exercício, você vai criar uma função equivalente a elem, mas usando uma função de alta ordem. Crie a função charFound :: Char -> String -> Bool que verifique se o caracter (primeiro argumento) está contido na string (segundo argumento). Exemplos de uso da função:-}
charFound :: Char -> String -> Bool
charFound ch str = any (ch==) str