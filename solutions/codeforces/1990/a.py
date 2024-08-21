t = int(input())

for _ in range(t):
    n = int(input())

    a = list(map(int, input().split()))

    freq = {}
    for ai in a:
        if ai not in freq:
            freq[ai] = 0
        freq[ai] += 1

    ret = False
    for x in freq.values():
        ret = ret or (x % 2 == 1)

    if ret:
        print("YES")
    else:
        print("NO")
