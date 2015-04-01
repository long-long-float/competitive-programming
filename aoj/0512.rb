table = [*?A..?Z]
puts gets.strip.chars.map{|c| table[table.index(c) - 3] }.join
