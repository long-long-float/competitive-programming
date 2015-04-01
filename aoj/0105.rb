dic = {}
while line = gets
  word, page = line.strip.split
  unless dic.key? word
    dic[word] = []
  end
  dic[word] << page.to_i
end

words = dic.keys.sort
words.each do |word|
  puts word
  puts dic[word].sort.join(' ')
end
