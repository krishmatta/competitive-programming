t = int(input())

for _ in range(t):
    n, k = tuple(map(int, input().split()))

    a = sorted(list(map(int, input().split())))

    ret = 0
    for x in a[:-1]:
        ret += 2 * x - 1

    print(ret)
