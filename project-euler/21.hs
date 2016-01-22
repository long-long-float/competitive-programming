d n = sum [m | m <- [1..n], n `mod` m == 0, n /= m]

main = print $ answer `div` 2
  where
    answer = sum $ concat $ [[n, m] | n <- [1..10000], let m = d n, m /= n, (d m) == n]
