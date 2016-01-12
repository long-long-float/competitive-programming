import Data.List (find)

main = print $ maybe 0 id (find is_eveny_divisible [1..])
  where
    is_eveny_divisible n = all (\m -> n `mod` m == 0) [1..20]
