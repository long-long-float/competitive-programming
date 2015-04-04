while true
  a, b, c = gets.split.map(&:to_i)
  break if a == 0 and b == 0 and c == 0

  states = Array.new(a + b + c + 1, 2)
  failed_lists = []

  n = gets.to_i
  n.times do
    i, j, k, r = gets.split.map(&:to_i)
    if r == 1
      states[i] = states[j] = states[k] = 1
    else
      failed_lists << [i, j, k]
    end
  end


  failed_lists.each do |failed_list|
    failed_list.delete_if{|n| states[n] == 1 }
    if failed_list.size == 1
      states[failed_list[0]] = 0
    end
  end

  puts states[1..-1]
end
