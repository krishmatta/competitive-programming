t = int(input())

for _ in range(t):
    a, b, c = tuple(map(int, input().split()))

    curr = [a, b, c]
    for _ in range(5):
        m = min(curr)
        curr.remove(m)
        curr.append(m + 1)
    print(curr[0] * curr[1] * curr[2])
