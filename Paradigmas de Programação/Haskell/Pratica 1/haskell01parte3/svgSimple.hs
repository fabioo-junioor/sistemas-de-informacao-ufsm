import Text.Printf

-- String inicial do SVG
svgBegin :: Float -> Float -> String
svgBegin w h = printf "<svg width='%.2f' height='%.2f' xmlns='http://www.w3.org/2000/svg'>\n" w h 

-- String final do SVG
svgEnd :: String
svgEnd = "</svg>"

svgCircle :: Int -> Int -> Int -> String -> String 
svgCircle x y r style = 
  printf "<circle cx='%d' cy='%d' r='%d' fill='%s' />\n" x y r style

-- Gera SVG com 2 círculos, um verde e um vermelho, com 0.4 de opacidade.
-- A opacidade pode não ser suportada em alguns visualizadores de SVG.
svgAll :: String
svgAll = 
  svgBegin 400 400 ++
  (svgCircle 190 210 100 "rgb(0, 0, 0, 0.1)") ++

  (svgCircle 190 120 50 "rgb(0, 0, 0, 0.1)") ++

  (svgCircle 180 110 50 "rgb(0, 0, 0, 1)") ++

  (svgCircle 160 82 15 "rgb(240, 248, 255, 1)") ++
  (svgCircle 200 82 15 "rgb(240, 248, 255, 1)") ++

  (svgCircle 192 77 7 "rgb(0, 0, 0, 1)") ++ 
  (svgCircle 168 77 7 "rgb(0, 0, 0, 1)") ++

  (svgCircle 180 200 100 "rgb(255, 0, 0, 1)") ++
  
  (svgCircle 120 150 20 "rgb(0, 0, 0, 1)") ++
  (svgCircle 240 150 20 "rgb(0, 0, 0, 1)") ++
  
  (svgCircle 150 190 20 "rgb(0, 0, 0, 1)") ++
  (svgCircle 210 190 20 "rgb(0, 0, 0, 1)") ++

  (svgCircle 220 250 25 "rgb(0, 0, 0, 1)") ++ 
  (svgCircle 140 250 25 "rgb(0, 0, 0, 1)") ++ 
  svgEnd

main :: IO ()
main = do
  writeFile "circles.svg" svgAll