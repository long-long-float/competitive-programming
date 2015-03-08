class Numeric
  def fact
    [*1..self].inject(&:*)
  end
end

n = gets.to_i
t = n.times.map{ gets }.map(&:to_i)

t = t.sort

ans1 = 0
num = 0
t.each do |t1|
  num += t1
  ans1 += num
end

puts ans1

puts t.group_by{|t| t }.values.map(&:size).map(&:fact).inject(&:*) % (10 ** 9 + 7)
