t = int(input())

def inn(x, l, r):
    return l <= x and x <= r

for _ in range(t):
    l, r = tuple(map(int, input().split()))
    L, R = tuple(map(int, input().split()))
    ret = 0
    for i in range(1, 100):
        if (inn(i, l, r) and inn(i + 1, L, R)) or (inn(i, L, R) and inn(i + 1, l, r)):
            ret += 1
    print(max(ret, 1))
