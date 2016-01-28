powersOfDigits n 1 = []
powersOfDigits n m = map ((^ n) . read . return) $ show m

digitPowers :: Int -> [Int]
digitPowers n = filter (\m -> (fromIntegral m) == (sum $ powersOfDigits n m)) [1..200000]

main = print $ sum $ digitPowers 5
