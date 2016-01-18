import Data.List

collatz :: Int -> [Int]
collatz 1 = [1]
collatz n =
  if even n then
    n : collatz (n `div` 2)
  else
    n : collatz (3 * n + 1)

main = print $ fst $ maximumBy (\(n, l) (n', l') -> compare l l') $ map (\m -> (m, length $ collatz m)) [n, n - 1..1]
  where
    n = 1000000
