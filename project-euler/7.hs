prime_seq n = filter_multiple n [2..]
  where
    filter_multiple 1 list = list
    filter_multiple n list = [m | m <- filter_multiple (n - 1) list, m == n || m `mod` n /= 0]

main = print $ (prime_seq n) !! (n - 1)
  where
    n = 10001
