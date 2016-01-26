import qualified Data.List as L

-- It can be found at Data.List, but I want to implement it :)
permutations :: Eq a => [a] -> [[a]]
permutations []  = []
permutations [x] = [[x]]
permutations list =
  concat [map ((:) n) $ permutations $ filter ((/=) n) list | n <- list]

main = print $ L.intercalate "" $ map show $ permutations [0..9] !! 999999
