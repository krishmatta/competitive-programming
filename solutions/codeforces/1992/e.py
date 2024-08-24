t = int(input())

for _ in range(t):
    ns = input()
    ni = int(ns)

    pfix = 0
    pfix_len = 0
    i = 0
    ret = []
    if ni == 1:
        for a in range(2, 10001):
            b = a - 1
            ret.append((a, b))
    else:
        while pfix <= ni * 10000:
            pfix = pfix * 10 + int(ns[i])
            pfix_len += 1

            asmin = (pfix_len + len(ns) - 1) // len(ns)
            bsmin = len(ns) - (i + 1)

            aimin = (pfix + (ni - 1)) // ni
            bimin = aimin * ni - pfix

            i = (i + 1) % len(ns)

            # bs = bsmin+len(n)*(a - asmin)
            # bi = bimin+n*(a-aimin)
            # bsmin + len(n) * (a - asmin) = bimin + n * (a - aimin)
            # (bsmin - bimin) + len(n) * a - len(n) * asmin = na - n * aimin
            # (bsmin - bimin) - len(n) * asmin + n * aimin = a (n - len(n))

            a_num = ((bsmin - bimin) - len(ns) * asmin + ni * aimin)
            a_denom = (ni - len(ns))
            if a_denom != 0 and a_num % a_denom == 0:
                a = a_num // a_denom
                b = bimin + ni * (a - aimin)
                if a >= 1 and a <= 10000 and b >= 1 and b <= min(10000, a * ni):
                    ret.append((a, b))
    print(len(ret))
    for a, b in ret:
        print(a, b)
