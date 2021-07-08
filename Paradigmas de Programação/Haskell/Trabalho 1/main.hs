import Text.Printf

type Point     = (Float,Float)
type Rect      = (Point,Float,Float)
type Circle    = (Point,Float)


-- Paletas de cores --
greenPalette :: Int -> Int -> [(Int,Int,Int)]
greenPalette n ton2 = [(0, ton1*ton2+i, 0) | i <- [0..n] ]
  where ton1 = 25

redPalette :: Int -> Int -> [(Int,Int,Int)]
redPalette n ton2 = [(ton1*ton2+i, 0, 0) | i <- [0..n] ]
  where ton1 = 25

bluePalette :: Int -> Int -> [(Int,Int,Int)]
bluePalette n ton2 = [(0, 0, ton1*ton2+i) | i <- [0..n] ]
  where ton1 = 25

purplePalette :: Int -> Int -> [(Int,Int,Int)]
purplePalette n ton2 = [(247, 37, ton1*ton2+i) | i <- [0..n] ]
  where ton1 = 25

grayPalette :: Int -> Int -> [(Int,Int,Int)]
grayPalette n ton2 = [(ton1*ton2+i, ton1*ton2+i, ton1*ton2+i) | i <- [0..n] ]
  where ton1 = 10

marinePalette :: Int -> Int -> [(Int,Int,Int)]
marinePalette n ton2 = [(ton1*ton2+i, 255, 225) | i <- [0..n] ]
  where ton1 = 5



-- Geração de quadrados em posições sequenciais --
genRectsInLine :: Int -> Float -> Float -> [Rect]
genRectsInLine n width height = [((m*(width+gap), vert), width, height) | m <- [0..fromIntegral (n-1)], vert <- [0,height/10..height/10*9]]
  where gap = 0



-- Strings SVG --
svgRect :: Rect -> String -> String 
svgRect ((x,y),w,h) style = 
  printf "<rect x='%.3f' y='%.3f' width='%.2f' height='%.2f' style='%s' />\n" x y w h style

svgBegin :: Float -> Float -> String
svgBegin w h = printf "<svg width='%.2f' height='%.2f' xmlns='http://www.w3.org/2000/svg'>\n" w h 

svgEnd :: String
svgEnd = "</svg>"

svgStyle :: (Int,Int,Int) -> String
svgStyle (r,g,b) = printf "fill:rgb(%d,%d,%d); mix-blend-mode: screen;" r g b


svgElements :: (a -> String -> String) -> [a] -> [String] -> String
svgElements func elements styles = concat $ zipWith func elements styles



-- Geração de quadrados para formação da letra --
faceIcon :: Float -> Float -> String
faceIcon width height = 
  svgRect((width/10*6,height/10*9), width/10,height/10) "fill:rgb(255,255,255)" ++
  svgRect((width/10*6,height/10*8), width/10,height/10) "fill:rgb(255,255,255)" ++
  svgRect((width/10*6,height/10*7), width/10,height/10) "fill:rgb(255,255,255)" ++
  svgRect((width/10*6,height/10*6), width/10,height/10) "fill:rgb(255,255,255)" ++
  svgRect((width/10*6,height/10*5), width/10,height/10) "fill:rgb(255,255,255)" ++
  svgRect((width/10*6,height/10*4), width/10,height/10) "fill:rgb(255,255,255)" ++
  svgRect((width/10*6,height/10*3), width/10,height/10) "fill:rgb(255,255,255)" ++
  svgRect((width/10*5,height/10*5), width/10,height/10) "fill:rgb(255,255,255)" ++
  svgRect((width/10*7,height/10*5), width/10,height/10) "fill:rgb(255,255,255)" ++
  svgRect((width/10*7,height/10*2), width/10,height/10) "fill:rgb(255,255,255)" ++
  svgRect((width/10*8,height/10*2), width/10,height/10) "fill:rgb(255,255,255)"
                                


-- Função principal que gera arquivo com imagem SVG --
-- Imagens geradas conforme entradas do usuario, determinda pelo -> (tamanho, cor, opacidade) --
main :: IO ()
main = do
  putStrLn "Informe a largura da imagem! "
  larguraImg <- getLine
  putStrLn "Informe a altura da imagem! "
  alturaImg <- getLine
  putStrLn "Informe o NUMERO referente a cor da imagem '[1]Vermelho', '[2]Azul', '[3]Verde', '[4]Rosa', '[5]Cinza', '[6]Marine'! "
  corFundo <- getLine
  putStrLn "Informe a opacidade da cor, num de '1 a 10'! "
  tonFundo <- getLine
    
  let svgstrs = svgBegin w h ++ svgfigs ++ icon ++ svgEnd
      svgfigs = svgElements svgRect rects (map svgStyle palette)
      rects = genRectsInLine nrects w h
      palette | read corFundo == 1 = redPalette nrects t
              | read corFundo == 2 = bluePalette nrects t
              | read corFundo == 3 = greenPalette nrects t
              | read corFundo == 4 = purplePalette nrects t
              | read corFundo == 5 = grayPalette nrects t
              | read corFundo == 6 = marinePalette nrects t
              | otherwise = bluePalette nrects t      
      icon = faceIcon w h 
      nrects = 100
      (w,h,t) = (read larguraImg, read alturaImg, read tonFundo)
    in writeFile "face-icon.svg" $ svgstrs