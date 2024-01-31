t = int(input())

for _ in range(t):
    n, m, k = [int(x) for x in input().split()]
    mod = (k - (n + m - 2)) % 4
    if mod % 2 or k < (n + m - 2):
        print("NO")
    else:
        print("YES")
        col = [["."] * (m - 1) for __ in range(n)]
        row = [["."] * m for __ in range(n - 1)]
        walk = [(0, 0)]
        if mod == 2:
            walk.append((0, 1))
            walk.append((1, 1))
            walk.append((1, 0))
        while walk[-1][0] < n - 1:
            walk.append((walk[-1][0] + 1, 0))
        while walk[-1][1] < m - 1:
            walk.append((n - 1, walk[-1][1] + 1))
        walk.append((walk[-1][0] - 1, walk[-1][1]))
        walk.append((walk[-1][0], walk[-1][1] - 1))
        walk.append((walk[-1][0] + 1, walk[-1][1]))

        curr_color = 0
        colors = ["B", "R"]
        for i, (a, b) in enumerate(walk):
            if not i:
                continue
            (c, d) = walk[i - 1]
            if a != c:
                if a < c:
                    row[a][b] = colors[curr_color]
                else:
                    row[c][d] = colors[curr_color]
            else:
                if b < d:
                    col[a][b] = colors[curr_color]
                else:
                    col[c][d] = colors[curr_color]
            curr_color = 1 - curr_color

        for i in range(len(col)):
            for j in range(len(col[0])):
                if col[i][j] == ".":
                    col[i][j] = colors[0]

        for i in range(len(row)):
            for j in range(len(row[0])):
                if row[i][j] == ".":
                    row[i][j] = colors[0]

        for i in col:
            for j in i:
                print(j, end=' ')
            print()

        for i in row:
            for j in i:
                print(j, end=' ')
            print()

