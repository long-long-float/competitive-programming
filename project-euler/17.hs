written n
  | n == 0 = []
  | n < 10 = [table0to9 !! n]
  | n <= 19 = [table10to19 !! (n - 10)]
  | n <= 99 = [table10to90 !! (n `div` 10 - 1)] ++ (written $ n `mod` 10)
  | n <= 999 =
    [table0to9 !! (n `div` 100), "hundred"] ++ (
          if null under99 then
            []
          else
            ["and"] ++ under99
        )
  | n == 1000 = ["one", "thousand"]
  | otherwise = error("n must be under 1000")
  where
    table0to9 = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    table10to19 = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
    table10to90 = ["ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]
    under99 = written $ n `mod` 100

main = print $ sum $ map length $ concat $ map written [1..n]
  where
    n = 1000
