-- Prática 02 de Haskell
-- Nome: Fabio Junior

import Funcoes

{-1 Médicos consideram que um indivíduo tem febre quando sua temperatura corpórea está acima de 37,8oC. Escreva uma função comFebre :: [Float] -> [Float] que, dada uma lista de temperaturas de indivíduos, selecione aquelas que representam febre. Resolva esta questão definindo uma função auxiliar nomeada, que verifica se uma dada temperatura é febre ou não.-}
comFebre :: [Float] -> [Float]
comFebre f = filter febre f


{-2 Escreva uma função comFebre' :: [Float] -> [Float] que resolva a questão anterior usando lambda.-}
comFebre' :: [Float] -> [Float]
comFebre' lista  = filter (\x -> (x > 37.8)) lista


{-3 Crie uma função itemize :: [String] -> [String] que receba uma lista de strings e adicione tags HTML <li> e </ li> antes e depois de cada string. Resolva esta questão usando lambda.-}
itemize :: [String] -> [String]
itemize str = map (\x -> "<li>"++ x ++"</li>") str


{-4 Escreva uma função bigCircles :: Float -> [Int] -> [Float] que receba um número e uma lista de raios de círculos. Essa função deverá retornar somente aqueles raios de círculos cuja área seja maior que o número passado como argumento.-}
bigCircles :: Float -> [Float] -> [Float]
bigCircles num raios = filter ((\x y -> x < (3.14* y^2)) num) raios


{-5 Escreva uma função quarentena :: [(String,Float)] -> [(String,Float)] que receba uma lista de tuplas com nomes de pessoas e suas temperaturas corpóreas, e selecione aquelas que têm febre.-}
quarentena :: [(String,Float)] -> [(String,Float)]
quarentena pessoa = filter (\(_,t) -> (febre t)) pessoa


{-6 Escreva uma função idadesEm :: [Int] -> Int -> [Int] que receba uma lista de anos de nascimento de algumas pessoas e um ano de referência. A lista resultante terá idades calculadas considerando o ano de referência (idades aproximadas, já que só consideram o ano, não a data completa de nascimento). Resolva esta questão usando lambda.-}
idadesEm :: [Int] -> Int -> [Int]
idadesEm lisAnos aRef = map (\x -> if anoRef aRef x then aRef - x else 0) lisAnos


{-7 Escreva uma função changeNames :: [String] -> [String] que receba uma lista de nomes e adicione o prefixo "Super " às strings que começarem com a letra A (maiúscula), deixando as demais inalteradas. A lista resultante, portanto, terá a mesma quantidade de strings da lista original.-}
changeNames :: [String] -> [String]
changeNames lisNomes = map (\x -> if head x == 'A' then "Super "++ x else x) lisNomes


{-8 Escreva uma função onlyShorts :: [String] -> [String] que receba uma lista de strings e retorne outra lista contendo somente as strings cujo tamanho seja menor que 5.-}
onlyShorts :: [String] -> [String]
onlyShorts listStr = filter (\x -> length x < 5) listStr