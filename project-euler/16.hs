pow :: Integer -> Integer -> Integer
pow n 0 = 1
pow n m = n * pow n (m - 1)

main = print $ sum $ map (read . return) $ show $ pow 2 1000
