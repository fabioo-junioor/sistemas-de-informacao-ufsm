-- Prática 06 de Haskell
-- Nome: Fabio Junior

{-1 Escreva uma função ends :: [Int] -> [Int] que receba uma lista e retorne outra lista contendo o primeiro e o último elementos da primeira lista. Use o operador de construção de lista (:).-}
ends :: [Int] -> [Int] 
ends [x] = [x]
ends (x:xs) = x : [last xs]


{-2 Reescreva a função deduzame do Aquecimento usando a notação (x:xs) para representar a lista lst. Ajuste o restante do código da função. Você verá que o código ficará mais enxuto.-}
deduzame :: [Integer] -> [Integer]
deduzame [] = []
deduzame (x:xs) = (2 * x) : deduzame (xs)


{-3 Reescreva também a função deduzame2 do Aquecimento, usando a notação (x:xs) para representar a lista lst.-}
deduzame2 :: [Integer] -> [Integer]
deduzame2 [] = []
deduzame2 (x:xs) = if x > 2
  then x : deduzame2 xs
  else deduzame2 xs


{-4 Usando recursão, escreva uma função geraTabela :: Int -> [(Int,Int)] que produza uma lista com n tuplas, cada tupla com números de n a 1 e seus respectivos quadrados. Exemplo:
> geraTabela 5
[(5,25),(4,16),(3,9),(2,4),(1,1)]
> geraTabela 0
[]-}
geraTabela :: Int -> [(Int,Int)]
geraTabela 0 = []
geraTabela n = (n, n^2) : geraTabela (n-1) 


{-5 Defina uma função recursiva que verifique se um dado caracter está contido numa string, conforme os exemplos abaixo:
> contido 'e' "andrea"
True
> contido 'x' "andrea"
False
> contido 'a' ""
False
Obs.: Neste exercício, não vale usar elem. Obs.: A tipagem da função contido é por sua conta!-}
contido :: Char -> String -> Bool
contido c "" = False
contido c (x:xs)
  | c == x = True
  | otherwise = c `contido` xs


{-6 Defina uma função recursiva translate, que receba uma lista de coordenadas de pontos 2D e desloque esses pontos em 2 unidades. A tipagem da função é por sua conta! Confira o exemplo abaixo:
> translate [(0.1,0.2),(1.1,6.0),(2.0,3.1)]
[(2.1,2.2),(3.1,8.0),(4.0,5.1)]-}
translate :: [(Float, Float)] -> [(Float, Float)]
translate [] = []
translate ((f,g): xs) = (f+2, g+2) : translate xs


{-7 Defina uma função recursiva countLongs, que receba uma lista de palavras e retorne a quantidade dessas palavras que tenham mais de 5 caracteres. A tipagem da função é por sua conta! Exemplo de uso:
> countLongs ["limao", "banana", "pera", "maracuja"]
2-}
countLongs :: [String] -> Int
countLongs [] = 0
countLongs (x:xs) 
  |length x >= 5 = 1 + countLongs xs
  |otherwise = countLongs xs


{-8 Defina uma função recursiva onlyLongs :: [String] -> [String] que receba uma lista de palavras e retorne outra lista somente com as palavras que tenham mais de 5 caracteres. Exemplo de uso:
> onlyLongs ["limao", "banana", "pera", "maracuja"]
["banana","maracuja"]-}
onlyLongs :: [String] -> [String]
onlyLongs [] = []
onlyLongs str  
  |(length (head str) >= 5) = (head str) : onlyLongs (tail str)
  |otherwise = onlyLongs (tail str)