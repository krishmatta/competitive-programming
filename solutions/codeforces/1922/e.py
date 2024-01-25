t = int(input())

for _ in range(t):
    x = int(input())
    ret = []
    first = True
    msb = 0
    curr = -1
    for i in range(63, -1, -1):
        a = 1 << i
        if (x & a) != 0:
            if first:
                msb = i
                for j in range(i):
                    ret.append(j * 100)
                first = False
            else:
                idx = len(ret) - i
                ret = ret[:idx] + [curr] + ret[idx:]
                curr -= 1
    print(len(ret))
    for x in ret:
        print(x, end=' ')
    print()
