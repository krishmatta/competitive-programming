t = int(input())

for _ in range(t):
    n, k = tuple(map(int, input().split()))

    ret = 1 if k else 0
    k = max(0, k - n)

    curr = n - 1
    flip = 0
    while k > 0:
        ret += 1
        k = max(0, k - curr)
        if flip:
            curr -= 1
        flip = 1 - flip
    print(ret)
