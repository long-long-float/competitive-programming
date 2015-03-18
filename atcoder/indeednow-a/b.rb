n = gets.to_i
n.times do
  s = gets.strip
  if s.chars.sort == 'indeednow'.chars.sort
    puts 'YES'
  else
    puts 'NO'
  end
end
