n = gets.to_i
h = n.times.map{ gets.to_i }

upping = true
ans, s, t, u = -1, 0, 0, 0
h.each_with_index do |_, i|
  next if i == 0

  if upping
    if h[i] > h[t]
      t = i
    else
      u = i
      upping = false
    end
  else
    if h[i] < h[u]
      u = i
    else
      ans = [ans, u - s].max
      s = i - 1
      t = i
      upping = true
    end
  end
end

puts [ans, h.size - 1 - s].max + 1
