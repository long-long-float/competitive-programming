import Data.List

{-
-- too slow :(
fibo 1 = 1
fibo 2 = 1
fibo n = fibo (n - 1) + fibo (n - 2)
-}
fibo = 1 : 1 : zipWith (+) fibo (tail fibo)

main = print $ snd answer
  where
    answer = case find (\(n, _) -> (digits n) >= 1000) $ zip fibo [1..] of
      Nothing -> error "no answer!"
      Just a -> a
    digits = length . show
