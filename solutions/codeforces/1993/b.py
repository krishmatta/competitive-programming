t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a = sorted(a)[::-1]
 
    ret = 0
    idx = -1
    for i in range(n):
        if a[i] & 1:
            idx = i
            break
 
    if idx == -1:
        print(ret)
        continue

    curr_mx = a[idx]
    for i in range(idx + 1, n):
        if not (a[i] & 1):
            ret += 1
            curr_mx += a[i]
 
    for i in range(idx - 1, -1, -1):
        if not (a[i] & 1):
            if a[i] > curr_mx:
                ret += 2
                curr_mx = float("inf")
            else:
                ret += 1
                curr_mx += a[i]
 
    print(ret)
