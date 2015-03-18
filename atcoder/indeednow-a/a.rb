puts 2.times.map{ gets }.map(&:strip).map(&:size).inject(&:*)
