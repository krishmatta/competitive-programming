from sys import stdout, exit
from collections import deque

def bfs(edges, i, j):
    adj = {}
    for x, y in edges:
        if x not in adj:
            adj[x] = []
        if y not in adj:
            adj[y] = []
        adj[x].append(y)
        adj[y].append(x)

    q = deque([i])
    vis = set([i])
    while q:
        curr = q.popleft()
        if curr == j:
            return True
        for neighbor in adj.get(curr, []):
            if neighbor not in vis:
                vis.add(neighbor)
                q.append(neighbor)
    return False

t = int(input())

for _ in range(t):
    n = int(input())

    ret = []

    def gen(i, j):
        if bfs(ret, i + 1, j + 1):
            return

        print("?", i + 1, j + 1)
        stdout.flush()

        mid = int(input())
        if mid == -1:
            exit()
        mid -= 1
        if mid == i:
            ret.append((i + 1, j + 1))
        else:
            gen(i, mid)
            gen(mid, j)

    for i in range(1, n):
        gen(0, i)

    print("!", " ".join(map(lambda z: str(z[0]) + " " + str(z[1]), ret)))
