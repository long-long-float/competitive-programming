import Text.Regex.Posix
import qualified Data.Text as T
import qualified Data.List as L
import qualified Data.Char as C

strip :: String -> String
strip s = s =~ "[A-Z]+"

main = do
  names <- readFile "p022_names.txt" >>=
    return . L.sort . map (strip . T.unpack) . T.split ((==) ',') . T.pack
  print $ sum $ scores names
  where
    scores names = map score $ zip names [1..]
    score (name, n) = n * (sum $ map (\c -> (C.ord c) - C.ord 'A' + 1) name)
