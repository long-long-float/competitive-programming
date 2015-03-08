table = {}

queue = [[[*'0'..'7'], 0]]
until queue.empty?
  current, num = queue.shift

  next if table[current]
  table[current] = num

  zero_pos = current.index('0')

  dists = [zero_pos - 4, zero_pos + 4]
  dists << zero_pos - 1 if zero_pos != 4
  dists << zero_pos + 1 if zero_pos != 3
  dists.each do |pos|
    next unless pos.between?(0, 7)

    current2 = current.dup
    current2[zero_pos], current2[pos] = current2[pos], current2[zero_pos]
    queue << [current2, num + 1]
  end
end

while line = gets
  puts table[line.split(' ')]
end
