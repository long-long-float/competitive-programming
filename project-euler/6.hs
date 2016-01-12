main = print $ squareOfSum - sumOfSquares
  where
    ns = [1..100]
    sumOfSquares = (sum . map (\n -> n * n)) ns
    squareOfSum  = n * n
      where
        n = sum ns
