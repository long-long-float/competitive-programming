while true
  a, b, c = gets.split.map(&:to_i)
  break if a == 0 and b == 0 and c == 0

  n = gets.to_i
  orig_fail_lists = []
  succeeded_lists = []
  n.times do
    i, j, k, r = gets.split.map(&:to_i)
    if r == 0
      orig_fail_lists << [i, j, k]
    else
      succeeded_lists << i << j << k
    end
  end

  fail_lists = orig_fail_lists.dup
  orig_fail_lists = orig_fail_lists.flatten.uniq

  succeeded_lists.uniq.each do |no|
    fail_lists.each do |fail_list|
      fail_list.delete(no)
    end
  end

  #pp fail_lists, orig_fail_lists

  1.upto(a + b + c) do |i|
    unless orig_fail_lists.include?(i)
      puts 2
      next
    end

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
    if failed
      puts 0
    elsif may_be_failed
      puts 2
    else
      puts 1
    end
  end

end
