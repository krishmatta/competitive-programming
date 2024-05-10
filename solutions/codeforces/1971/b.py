t = int(input())

for _ in range(t):
    s = input()
    freq = {}
    good = False
    done = False
    ret = ""
    for i, x in enumerate(s):
        if x not in freq:
            freq[x] = 0
            if i:
                good = True
                if not done:
                    done = True
                    ret = x + ret
                else:
                    ret = x + ret
            else:
                ret = ret + x
        else:
            ret = ret + x
        freq[x] += 1


    if good:
        print("YES")
        print(ret)
    else:
        print("NO")
