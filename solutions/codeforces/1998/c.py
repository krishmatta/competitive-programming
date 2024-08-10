def check(ab, k, med):
    i = len(ab) - 2
    num_geq = 0
    cost = 0
    while i > -1 and num_geq < ((len(ab) - 1) // 2) + 1:
        if ab[i][0] >= med:
            num_geq += 1
        elif ab[i][1]:
            num_geq += 1
            cost += med - ab[i][0]
        i -= 1
    return num_geq >= ((len(ab) - 1) // 2) + 1 and cost <= k

t = int(input())

for _ in range(t):
    n, k = tuple(map(int, input().split()))
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    ab = sorted(zip(a, b))

    mx = ab[-1][0]
    med_idx = (len(ab) // 2) - 1
    med = ab[med_idx][0]

    ret = mx + med

    # increase max
    i = len(ab) - 1
    while i > -1 and ab[i][1] == 0:
        i -= 1

    if i > -1 and (mx - ab[i][0]) <= k:
        new_med = med
        if i < len(ab) - 1:
            if len(ab) == 2:
                new_med = mx
            else:
                if i <= med_idx:
                    new_med = ab[med_idx + 1][0]
        new_mx = k + ab[i][0]
        ret = max(ret, new_med + new_mx)

    # increase med
    lo = 1
    hi = mx - 1
    while lo < hi:
        mid = lo + (hi - lo + 1) // 2
        if check(ab, k, mid):
            lo = mid
        else:
            hi = mid - 1
    ret = max(ret, lo + mx)

    print(ret)
