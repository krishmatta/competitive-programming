t = int(input())

for _ in range(t):
    n, x = tuple(map(int, input().split()))
    a = list(map(int, input().split()))
    ret = 1
    divisors = set([1])
    for ai in a:
        to_add = []
        for divisor in divisors:
            nxt = ai * divisor
            if x % nxt == 0:
                to_add.append(nxt)
        for add in to_add:
            divisors.add(add)
        if x in divisors:
            divisors = set([1, ai])
            ret += 1
    print(ret)
