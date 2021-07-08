module Funcoes
(
febre,
anoRef
)where

febre :: Float -> Bool
febre f1 = if f1 > 38.80 then True else False

anoRef :: Int -> Int -> Bool
anoRef x y = if x > y then True else False