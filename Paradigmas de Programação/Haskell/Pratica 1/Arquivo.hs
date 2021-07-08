module Arquivo
(
htmlItem,
isVowel,
circleArea,
isElderly,
isLongWord,
isEvenBetter,
between,
noSpace
)where

htmlItem :: String -> String
htmlItem nome = "<li>"++  nome ++"</li>"

isVowel :: Char -> Bool
isVowel vogal = if vogal == 'a' || vogal == 'e' || vogal == 'i' || vogal == 'o' || vogal == 'u' then True else False

circleArea :: Float -> Float
circleArea r = 3.14 * r^2

isElderly :: Int -> Bool
isElderly idade = idade > 65

isLongWord :: String -> Bool
isLongWord s = length s > 10

isEvenBetter  :: Int -> Bool
isEvenBetter n = mod n 2 == 0

between :: Int -> Bool
between i = if i >= 60 && i <= 80 then True else False

noSpace :: Char -> Bool
noSpace spa = spa == ' '