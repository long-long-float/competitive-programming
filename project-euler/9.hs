main = print [a * b * c | a <- ns, b <- ns, c <- ns, a + b + c == 1000, a^2 + b^2 == c^2]
  where
    ns = [0..1000]
