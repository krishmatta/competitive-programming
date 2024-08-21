t = int(input())

for _ in range(t):
    n, x, y = tuple(map(int, input().split()))

    ret = [1 for _ in range(n)]
    for i in range(x, n, 2):
        ret[i] = -1

    for i in range(y - 2, -1, -2):
        ret[i] = -1

    print(" ".join(map(str, ret)))
