-- Prática 01 de Haskell - Parte 1
-- Nome: Fabio Junior

{-1 Crie uma função sumSquares :: Int -> Int -> Int que receba dois números x e y e calcule a soma dos seus quadrados.-}
sumSquares :: Int -> Int -> Int
sumSquares x y = x^2 + y^2


{-2 Defina a função circleArea :: Float -> Float que receba um raio r e calcule a área de um círculo com esse raio, dada por pi vezes o raio ao quadrado. Dica: Haskell tem a função pi pré-definida.-}
circleArea :: Float -> Float
circleArea r = 3.14 * r^2

{-3 Defina uma função age :: Int -> Int -> Int que receba o ano de nascimento de uma pessoa e o ano atual, produzindo como resultado a idade (aproximada) da pessoa.-}
age :: Int -> Int -> Int
age anoNasc anoAt = anoAt - anoNasc


{-4 Defina uma função isElderly :: Int -> Bool que receba uma idade e resulte verdadeiro caso a idade seja maior que 65 anos.-}
isElderly :: Int -> Bool
isElderly idade = idade > 65


{-5 Defina uma função htmlItem :: String -> String que receba uma String e adicione tags <li> e <\li> como prefixo e sufixo, respectivamente. Por exemplo, se a entrada for "abc", a saída será "<li>abc<\li>". Use o operador ++ para concatenar strings (este operador serve para concatenar quaisquer lista do mesmo tipo).-}
htmlItem :: String -> String
htmlItem nome = "<li>"++  nome ++"</li>"


{-6 Crie uma função startsWithA :: String -> Bool que receba uma string e verifique se ela inicia com o caracter 'A'-}
startsWithA :: String -> Bool
startsWithA primeira = head primeira == 'A'


{-7 Defina uma função isVerb :: String -> Bool que receba uma string e verifique se ela termina com o caracter 'r'. Antes desse exercício, teste no interpretador a função pré-definida last, que retorna o último elemento de uma lista. Dica: conheça também o list monster, do autor Miran Lipovača :-)-}
isVerb :: String -> Bool
isVerb str3 = last str3 == 'r'


{-8 Crie uma função isVowel :: Char -> Bool que receba um caracter e verifique se ele é uma vogal minúscula.-}
isVowel :: Char -> Bool
isVowel vogal = if vogal == 'a' || vogal == 'e' || vogal == 'i' || vogal == 'o' || vogal == 'u' then True else False


{-9 Crie uma função hasEqHeads :: [Int] -> [Int] -> Bool que verifique se 2 listas possuem o mesmo primeiro elemento. Use a função head e o operador lógico == para verificar igualdade.-}
hasEqHeads :: [Int] -> [Int] -> Bool
hasEqHeads lista1 lista2 = head lista1 == head lista2


{-10 A função pré-definida elem recebe um elemento e uma lista, e verifica se o elemento está presente ou não na lista. Teste essa função no interpretador:
elem 3 [1,2,3]
elem 4 [1,2,3]
elem 'c' "abcd"
elem 'A' "abcd"-}
isVowel2 :: Char -> Bool
isVowel2 res = elem res ['a','A','e','E','i','I','o','O','u','U']
