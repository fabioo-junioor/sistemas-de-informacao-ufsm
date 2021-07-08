-- Prática 04 de Haskell
-- Nome: Fabio Junior


{-1 A vacinação contra COVID19 no Brasil está acontecendo por grupos prioritários. As equipes responsáveis pelas ações de vacinação devem registrar em um sistema cada dose de vacina aplicada, classificando cada indivíduo em um dos grupos previstos. No caso de idosos, este grupo prioritário é organizado em 5 faixas etárias: de 60 a 64 anos, de 65 a 69 anos. de 70 a 74 anos, de 75 a 79 anos e de 80 anos ou mais. No sistema, essas faixas são identificadas, respectivamente, pelas siglas "IDO64", "IDO69", "IDO74", "IDO79" e "IDO80". Sabendo disso, crie uma função faixaIdoso :: Int -> String que receba uma idade e retorne o código da faixa correspondente. Caso a idade não se enquadre em nenhuma das faixas do grupo prioritário, o código será "ND" (não definido).-}
faixaIdoso :: Int -> String
faixaIdoso idade | idade >= 60 && idade < 65 = "IDO64" | idade >= 65 && idade < 70 = "IDO69"
                 | idade >= 70 && idade < 75 = "IDO75" | idade >= 75 && idade < 80 = "IDO79"
                 | idade >= 80 = "IDO80" | otherwise = "ND"


{-2 Usando list comprehension, crie uma função classifIdosos :: [(String,Int)] -> [(String,Int,String)] que receba uma lista de tuplas contendo nome e idade, e retorne uma lista de tuplas com nome, idade e o código da faixa correspondente (faixaIdoso). Por exemplo:
> classifIdosos [("joao",65), ("maria", 64)]
[("joao",65,"IDO69"),("maria",64,"IDO64")]-}
classifIdosos :: [(String,Int)] -> [(String,Int,String)]
classifIdosos ls = [(nome,idade, faixaIdoso idade) | (nome,idade) <- ls]


{-3 Resolva o exercício anterior com função de alta ordem, sem usar list comprehension. O novo nome da função será classifIdosos'.-}
classifIdosos' :: [(String,Int)] -> [(String,Int,String)]
classifIdosos' ls = map (\(x,y) -> (x, y, faixaIdoso y)) ls


{-4 Suponha que uma cor seja representada por uma tupla (Int,Int,Int), contendo valores (R=red,G=Green,B=blue). Considerando isso, crie uma função strColor :: (Int,Int,Int) -> String que receba uma tupla representando uma cor (R=red,G=Green,B=blue) e retorne uma string no formato "rgb(R,G,B)". Por exemplo:
> strColor (90,0,35)
"rgb(90,0,35)"-}
strColor :: (Int,Int,Int) -> String
strColor (r,g,b) = "rgb"++ "("++ show r ++ "," ++ show g ++ "," ++ show b ++ ")"


{-5 Suponha que um círculo seja representado por uma tupla (Int,Int,Int), contendo respectivamente as coordenadas x e y de seu centro, seguidas de seu raio. Considerando isso, crie uma função genCircs :: Int -> (Int,Int) -> Int -> [(Int,Int,Int)] que receba um número N, um ponto (cx,cy) e um raio R, e gere uma sequência de N círculos de raio R alinhados horizontalmente com um primeiro círculo centrado em (cx,cy). Você pode decidir qual será a distância entre eles. Por exemplo:
> genCircs 5 (10,10) 2
[(10,10,2),(14,10,2),(18,10,2),(22,10,2),(26,10,2)]-}
genCircs :: Int -> (Int,Int) -> Int -> [(Int,Int,Int)]
genCircs q (cx,cy) raio = take q [(x,cy,raio) | x <- (iterate(+2) cx)]


{-6 Suponha novamente que uma cor seja representada por uma tupla (Int,Int,Int), contendo valores (R=red,G=Green,B=blue). Sabendo disso, crie uma função genReds :: Int -> [(Int,Int.Int)] que receba um número N e gere uma lista com N tons de vermelho calculados (não enumere cada um dos valores literalmente com números "hard-coded"). Você pode repetir valores, se desejar. Abaixo está um exemplo de uso dessa função:
> genReds 5
[(80,0,0),(90,0,0),(100,0,0),(110,0,0),(120,0,0)]-}
genReds :: Int -> [(Int,Int,Int)]
genReds list = take list [(z,0,0) | z <- (iterate(\x -> x*2) list)] 