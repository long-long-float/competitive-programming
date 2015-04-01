while true
  a, b = gets.split.map(&:to_i)
  break if a == 0 and b == 0
  map = Array.new(a + 1){ Array.new(b + 1, 0) }
  n = gets.to_i
  n.times do
    x, y = gets.split.map(&:to_i)
    map[x][y] = nil
  end

  map[1][1] = 1
  1.upto(a) do |x|
    1.upto(b) do |y|
      next unless map[x][y]
      map[x][y + 1] += map[x][y] if y + 1 <= b and map[x][y + 1]
      map[x + 1][y] += map[x][y] if x + 1 <= a and map[x + 1][y]
    end
  end
  puts map[a][b]
end
