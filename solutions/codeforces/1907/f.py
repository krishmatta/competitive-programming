t = int(input())

for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]

    ret = int(1e5)
    inc_idx = 0
    inc = True
    for i in range(1, len(a)):
        if a[i] < a[i - 1]:
            if inc_idx:
                inc = False
                break
            inc_idx = i
    if a[-1] > a[0]:
        inc = False
    if inc_idx == 0:
        ret = min(ret, 0)
    elif inc:
        ret = min(ret, n - inc_idx)
        ret = min(ret, 2 + inc_idx)

    dec_idx = 0
    dec = True
    for i in range(1, len(a)):
        if a[i] > a[i - 1]:
            if dec_idx:
                dec = False
                break
            dec_idx = i
    if a[-1] < a[0]:
        dec = False
    if dec_idx == 0:
        ret = min(ret, 1)
    elif dec:
        ret = min(ret, n + 1 - dec_idx)
        ret = min(ret, 1 + dec_idx)
    if ret == int(1e5):
        print(-1)
    else:
        print(ret)
