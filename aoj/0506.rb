while true
  n = gets.to_i
  break if n == 0
  s = gets.strip

  n.times do |i|
    curc = nil
    count = 0
    temp_s = []
    s.each_char do |c|
      unless curc
        curc = c
      end
      if curc != c
        temp_s << count << curc
        count = 1
      else
        count += 1
      end
      curc = c
    end
    temp_s << count << curc if curc
    s = temp_s.join

  end
  puts s
end
