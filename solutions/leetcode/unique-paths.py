class Solution:
  def uniquePaths(self, m: int, n: int):
    dp = [[0 for _ in range(n)] for __ in range(m)]
    dp[0][0] = 1

    for i in range(m):
      for j in range(n):
        curr = dp[i][j]
        if i > 0:
          curr += dp[i - 1][j]
        if j > 0:
          curr += dp[i][j - 1]
        dp[i][j] = curr

    return dp[m - 1][n - 1]
