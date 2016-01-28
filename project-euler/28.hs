spiralDiagonals 1 = [1]
spiralDiagonals n =
  nmax : (nmax - n + 1) : (nmax - 2 * n + 2) : (nmax - 3 * n + 3) : spiralDiagonals (n - 2)
  where
    nmax = n * n

main = print $ sum $ spiralDiagonals 1001
