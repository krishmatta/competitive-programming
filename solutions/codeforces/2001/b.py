from collections import deque

t = int(input())

for _ in range(t):
    n = int(input())
    if not n % 2:
        print(-1)
        continue
    ret = deque([1])
    while len(ret) < n:
        if len(ret) % 2:
            ret.append(len(ret) + 1)
        else:
            ret.appendleft(len(ret) + 1)
    print(" ".join(map(str, list(ret))))
