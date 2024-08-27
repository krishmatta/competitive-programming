t = int(input())

for _ in range(t):
    n = int(input())
    s = input()

    freq = {}
    for x in s:
        if x not in freq:
            freq[x] = 0
        freq[x] += 1

    ret = []
    while True:
        stop = True
        for x, y in freq.items():
            if y:
                ret.append(x)
                freq[x] -= 1
                stop = False
        if stop:
            break
    print("".join(ret))

