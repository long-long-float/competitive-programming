def get_ints
  gets.split.map(&:to_i)
end

while true
  n, m = get_ints
  break if n == 0 and m == 0

  nums = Array.new(m){|i| [i + 1, 0] }.reverse
  n.times do
    gets.strip.split.each_with_index do |c, i|
      if c == '1'
        nums[-(i + 1)][1] += 1
      end
    end
  end

  puts nums.sort_by.with_index{|(_, c), i| [c, i] }.reverse.map{|i, _| i }.join(' ')
end
