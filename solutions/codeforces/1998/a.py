t = int(input())

def gen_unique(x, k):
    ret = []
    for i in range(1, k // 2 + 1):
        ret.append(x - i)
        ret.append(x + i)
    if (k % 2):
        ret.append(x)
    return ret

for _ in range(t):
    xc, yc, k = tuple(map(int, input().split()))
    x = gen_unique(xc, k)
    y = gen_unique(yc, k)
    for xi, yi in map(tuple, zip(x, y)):
        print(xi, yi)
