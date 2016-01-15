import Data.Numbers.Primes -- it's cheat :(

--primes = filter_multiple [2..]
--  where
--    filter_multiple (x:xs) = x : filter_multiple [n | n <- xs, n `mod` x /= 0]

main = (print . sum . takeWhile ((>) n)) primes
  where
    n = 2000000
