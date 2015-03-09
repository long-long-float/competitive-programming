while true
  n = gets.to_i
  break if n == 0

  a, b = 0, 0
  n.times do
    a_, b_ = gets.split.map(&:to_i)
    sum = a_ + b_
    if a_ > b_
      a += sum
    elsif b_ > a_
      b += sum
    else
      a += a_
      b += b_
    end
  end

  puts "#{a} #{b}"
end
