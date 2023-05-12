class Solution:
  def longestPalindrome(self, s : str) -> str:
    dp = [[False for i in range(len(s) + 1)] for _ in range(len(s) + 1)]
    mx = (0, 1)

    def getLn(rng):
      return rng[1] - rng[0]

    for i in range(len(s)):
      dp[i][i + 1] = True

    for i in range(len(s) - 1):
      dp[i][i + 2] = s[i] == s[i + 1]
      if dp[i][i + 2]:
        mx = (i, i + 2)

    for ln in range(3, len(s) + 1):
      for i in range(len(s) - ln + 1):
        j = i + ln
        if dp[i + 1][j - 1] and s[i] == s[j - 1]:
          dp[i][j] = True
          if getLn((i, j)) > getLn(mx):
            mx = (i, j)

    return s[mx[0]:mx[1]]
