t = int(input())

for _ in range(t):
    n = int(input())

    a = list(map(int, input().split()))

    freq = {}
    mx = 0
    for ai in a:
        if ai not in freq:
            freq[ai] = 0
        freq[ai] += 1
        mx = max(mx, freq[ai])

    print(n - mx)
