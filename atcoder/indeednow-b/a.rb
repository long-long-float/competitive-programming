require 'scanf'
a = scanf('%d %d')
b = scanf('%d %d')
puts (a[0] - b[0]).abs + (a[1] - b[1]).abs + 1
