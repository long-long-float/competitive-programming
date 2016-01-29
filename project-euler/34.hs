fact 0 = 1
fact n = fact (n - 1) * n

digitFacts :: Int -> [Int]
digitFacts = map (fact . read . return) . show

main = print $ sum $ filter (\n -> n == (sum $ digitFacts n)) [3..100000]
