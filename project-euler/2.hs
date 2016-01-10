fibo 0 = 1
fibo 1 = 2
fibo n = (fibo $ n - 1) + (fibo $ n - 2)

main = do
  print $ (sum . filter even . takeWhile (\n -> n <= 4000000) . map fibo) [0..]
