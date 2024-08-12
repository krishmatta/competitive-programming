t = int(input())

for _ in range(t):
    n, m, k = tuple(map(int, input().split()))
    print(min(n, k) * min(m, k))
