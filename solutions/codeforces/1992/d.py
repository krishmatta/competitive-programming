t = int(input())

for _ in range(t):
    n, m, k = tuple(map(int, input().split()))

    s = "L" + input()

    dp = [float("inf") for _ in range(n + 1)]
    def get(i):
        if i >= n + 1:
            return 0
        return dp[i]

    for i in range(n, -1, -1):
        if s[i] == "W":
            dp[i] = 1 + get(i + 1)
        elif s[i] == "L":
            ret = float("inf")
            for j in range(1, m + 1):
                ret = min(ret, get(i + j))
            dp[i] = ret

    if dp[0] <= k:
        print("YES")
    else:
        print("NO")
