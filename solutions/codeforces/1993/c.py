t = int(input())

for _ in range(t):
    n, k = tuple(map(int, input().split()))
    a = list(map(int, input().split()))
    mx = max(a)
    ret_lb = mx
    ret_ub = mx + k
    for x in a:
        curr = (mx - x) // k
        if curr % 2:
            ret_lb = max(ret_lb, x + k * (curr + 1))
        else:
            ret_ub = min(ret_ub, x + k * (curr + 1))
    if ret_ub <= ret_lb:
        print(-1)
    else:
        print(ret_lb)
