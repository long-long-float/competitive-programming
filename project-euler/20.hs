fact 0 = 1
fact n = n * fact (n - 1)

main = print $ sum $ map (read . return) $ show $ fact 100
