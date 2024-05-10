t = int(input())

for _ in range(t):
    s = input()

    ret = 0

    transition = False
    prev = '0'
    if s[0] == '1':
        prev = '1'

    for x in s:
        if prev == '1' and x == '0':
            ret += 1
        if prev == '0' and x == '1':
            if transition:
                ret += 1
            else:
                transition = True
        prev = x
    print(ret + 1)
