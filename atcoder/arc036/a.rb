n, k = gets.split.map(&:to_i)
t = n.times.map{ gets.to_i }
flag = false
t.each_with_index do |_, i|
  next if i < 2
  if t[i] + t[i - 1] + t[i - 2] < k and !flag
    puts i + 1
    flag = true
  end
end

puts -1 unless flag
