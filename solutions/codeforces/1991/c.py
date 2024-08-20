t = int(input())

while t:
    n = int(input())
    a = set(map(int, input().split()))

    a = sorted(list(a))

    bad = False
    for i in range(1, len(a)):
        if (a[i] % 2) != (a[i - 1] % 2):
            bad = True
            break

    if bad:
        print(-1)
        t -= 1
        continue

    ret = []
    while len(ret) < 40:
        mid = ((a[len(a) - 1]) + (a[0])) // 2
        ret.append(mid)
        a = sorted(list(set(map(lambda z: abs(z - mid), a))))

    if len(a) > 1 or a[0] != 0:
        print(-1)
    else:
        print(len(ret))
        print(" ".join(map(str, ret)))

    t -= 1
