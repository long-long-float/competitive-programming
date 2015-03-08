require 'pp'

def print_field(field)
  field.each do |row|
    puts row.join(' ')
  end
  puts '-----'
end

while line = gets
  row, col = line.split(' ').map(&:to_i)
  break if row == 0 and col == 0

  field = row.times.map{ gets.split(' ').map(&:to_i) }

  ans = -1

  0.upto(2 ** row - 1) do |i|
    field2 = field.map.with_index do |row, y|
      (i[y] == 1 ? row.map{|c| 1 - c } : row.dup)
    end

    flatten_f2 = field2.flatten
    flip_to = flatten_f2.count(1) > flatten_f2.size ? 1 : 0

    col.times do |c|
      num = field2.count{|row| row[c] == flip_to }
      if num <= row / 2
        field2.each{|row| row[c] = 1 - row[c] }
      end
    end

    ans = [ans, field2.flatten.count(flip_to)].max
  end

  puts ans
end
