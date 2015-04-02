while true
  a, b, c = gets.split.map(&:to_i)
  break if a == 0 and b == 0 and c == 0

  n = gets.to_i
  fail_lists = []
  n.times do
    i, j, k, r = gets.split.map(&:to_i)
    if r == 0
      fail_lists << [i, j, k]
    else
      fail_lists.each do |fail_list|
        fail_list.delete(i)
        fail_list.delete(j)
        fail_list.delete(k)
      end
    end
  end

  1.upto(a + b + c) do |i|
    failed = false
    may_be_failed = false
    fail_lists.each do |fail_list|
      if fail_list.include?(i)
        if fail_list.size == 1
          failed = true
          break
        else
          may_be_failed = true
        end
      end
    end
    if may_be_failed
      puts 2
    elsif failed
      puts 0
    else
      puts 1
    end
  end
end
