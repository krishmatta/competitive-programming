t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    print(sorted(a)[len(a) // 2])
