t = int(input())

for _ in range(t):
    n = int(input())
    x = sorted(list(map(int, input().split())))
    if n > 2:
        print("NO")
    elif n == 2 and x[1] - x[0] == 1:
        print("NO")
    else:
        print("YES")
