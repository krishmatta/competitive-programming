t = int(input())

for _ in range(t):
    a, b, c, d = map(int, input().split())

    ret = False

    c_side = False
    d_side = False

    i = a
    while i != b:
        if c == i:
            c_side = True
        if d == i:
            d_side = True
        i += 1
        if i == 13:
            i = 1

    if c_side != d_side:
        ret = True

    if ret:
        print("YES")
    else:
        print("NO")
