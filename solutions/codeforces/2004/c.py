t = int(input())

for _ in range(t):
    n, k = tuple(map(int, input().split()))
    a = sorted(list(map(int, input().split())))[::-1]

    ret = 0
    for i in range(0, n, 2):
        ret += a[i]
        if i + 1 < n:
            diff = a[i] - a[i + 1]
            ret -= a[i + 1] + min(diff, k)
            k = max(0, k - diff)
    print(ret)
