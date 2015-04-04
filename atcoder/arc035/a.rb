s = gets.strip

yes = true

(s.size / 2).times do |i|
  h = s[i]
  t = s[-i - 1]

  next if h == '*' or t == '*'
  next if h == t

  yes = false
  break
end

puts yes ? 'YES' : 'NO'
