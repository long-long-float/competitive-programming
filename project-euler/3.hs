main = print $ find_largest_prime_factor $ (truncate . sqrt . fromIntegral) a
  where
    a = 600851475143
    is_prime n = all (\m -> n `mod` m /= 0) [2..n - 1]
    find_largest_prime_factor n =
      if a `mod` n == 0 && is_prime n then n else find_largest_prime_factor $ n - 1
