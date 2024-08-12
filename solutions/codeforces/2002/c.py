def dist(x, y):
    return (y[0] - x[0]) ** 2 + (y[1] - x[1]) ** 2

t = int(input())

for _ in range(t):
    n = int(input())
    xy = []
    for _ in range(n):
        xy.append(tuple(map(int, input().split())))

    xyxy = tuple(map(int, input().split()))
    xys = (xyxy[0], xyxy[1])
    xyt = (xyxy[2], xyxy[3])

    ret = True

    for xyi in xy:
        idist = dist(xyt, xyi)
        sdist = dist(xyt, xys)

        if idist <= sdist:
            ret = False
            break

    if ret:
        print("YES")
    else:
        print("NO")
