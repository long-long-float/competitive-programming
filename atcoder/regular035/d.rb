class Numeric
  def fact
    [*1..self].inject(&:*) || 1
  end
end

def calc_route(checkpoints, i)
  a, b = checkpoints[i], checkpoints[i + 1]
  dx, dy = b[0] - a[0], b[1] - a[1]

  (dx + dy).fact / (dx.fact * dy.fact)
end

N = gets.to_i
checkpoints = N.times.map{ gets.split.map(&:to_i) }

routes = (checkpoints.size - 1).times.map do |i|
  calc_route(checkpoints, i)
end

Q = gets.to_i

Q.times do
  t = gets.split.map(&:to_i)

  if t[0] == 1
    checkpoints[t[1] - 1] = t[2, 3]
    routes[t[1] - 2] = calc_route(checkpoints, t[1] - 1)
    routes[t[1] - 1] = calc_route(checkpoints, t[1])
  else
    r1 = routes[(t[1] - 1)...t[2]].inject(&:*)
    r2 = routes[(t[3] - 1)...t[4]].inject(&:*)

    puts r1 > r2 ? 'FIRST' : 'SECOND'
  end
end
