t = int(input())

for _ in range(t):
    n, m, k = tuple(map(int, input().split()))

    ret = []
    for x in range(n, k - 1, -1):
        ret.append(x)
    for x in range(m + 1, k):
        ret.append(x)
    for x in range(1, m + 1):
        ret.append(x)
    print(" ".join(map(str, ret)))
