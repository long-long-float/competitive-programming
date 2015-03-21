while True:
    d = (1, 3, 6, 4, 5, 2)

    n = int(raw_input())
    if n == 0: break

    ans = d[0]
    for i in xrange(n):
        dire = raw_input()
        if dire == "North":
            d = d[5], d[1], d[4], d[3], d[0], d[2]
        elif dire == "East":
            d = d[3], d[0], d[1], d[2], d[4], d[5]
        elif dire == "West":
            d = d[1], d[2], d[3], d[0], d[4], d[5]
        elif dire == "South":
            d = d[4], d[1], d[5], d[3], d[2], d[0]
        elif dire == "Right":
            d = d[0], d[4], d[2], d[5], d[3], d[1]
        elif dire == "Left":
            d = d[0], d[5], d[2], d[4], d[1], d[3]
        ans += d[0]
    print ans
