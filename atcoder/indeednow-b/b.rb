s, t = gets.strip.chars.to_a, gets.strip.chars.to_a
s2 = s.dup

ans = 0
while true
  if s2 == t
    break
  end

  s2.unshift(s2.pop)
  ans += 1

  if s2 == s
    ans = -1
    break
  end
end

puts ans
