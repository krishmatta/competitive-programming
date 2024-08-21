t = int(input())

for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    ret = sum(a)

    mad = 0
    mads = []
    freq = {}
    for x in a:
        if x not in freq:
            freq[x] = 0
        freq[x] += 1
        if freq[x] > 1:
            mad = max(mad, x)
        mads.append(mad)

    ret += sum(mads)

    prev = 0
    mad_freq = {}
    for i, x in enumerate(mads):
        if x not in mad_freq:
            mad_freq[x] = 0

        if mad_freq[x]:
            ret += x * (n - i)
            prev = x
        else:
            ret += prev * (n - i)
        mad_freq[x] += 1
    print(ret)
