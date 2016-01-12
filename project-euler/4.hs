is_palindromic n = nstr == reverse nstr
  where
    nstr = show n

main = print answer
  where
    nums = [999, 998..0]
    answer = maximum [n * m | n <- nums, m <- nums, is_palindromic (n * m)]
