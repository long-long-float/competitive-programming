n = gets.to_i
s = n.times.map{ gets.to_i }.sort.reverse.group_by{|_| _}.to_a.map do |_, c|
  [_ == 0 ? -1 : _, c.size]
end
q = gets.to_i
k = q.times.map{ gets.to_i }

k.each do |k1|
  s.each do |score, num|
    k1 -= num
    if k1 < 0
      puts score + 1
      break
    end
  end
end
