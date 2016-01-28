distinctTerms a b = [m ^ n | m <- [2..a], n <- [2..b]]
uniq list = foldl (\xs x -> if x `elem` xs then xs else (x:xs)) [] list

main = print $ length $ uniq $ distinctTerms 100 100
