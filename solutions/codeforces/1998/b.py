t = int(input())

for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))
    p = [p[-1]] + p[:-1]
    for x in p:
        print(x, end=' ')
    print()
