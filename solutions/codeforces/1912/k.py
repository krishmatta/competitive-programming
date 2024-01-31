import sys

n = int(input())
a = [int(x) for x in input().split()]
MOD = 998244353
dp = {}

dp = [[[0] * 2 for _ in range(2)] for __ in range(n)]
dp[0][a[0] % 2][0] = 1
dp[0][a[0] % 2][1] = 1
for i in range(1, n):
    for j in range(2):
        for k in range(2):
            ret = dp[i - 1][j][k]
            if (a[i] % 2) == j:
                ret += 1
                if not j:
                    if k:
                        ret += dp[i-1][k][1]
                        ret %= MOD
                    else:
                        ret += dp[i-1][k][0]
                        ret %= MOD
                else:
                    if k:
                        ret += dp[i-1][k][0]
                        ret %= MOD
                    else:
                        ret += dp[i-1][k][1]
                        ret %= MOD

            dp[i][j][k] = ret

ret = 0
for i in range(2):
    for j in range(2):
        ret += dp[len(a) - 1][i][j]
        ret %= MOD
print((ret - 2 * n - ((n * (n - 1)) // 2)) % MOD)
