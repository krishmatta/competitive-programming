class Solution:
  def wordBreak(self, s: str, wordDict: List[str]) -> bool:
    words = set()
    for word in wordDict:
      words.add(word)

    memo = {}

    def solve(curr):
      if len(curr) == 0:
        return True
      if curr not in memo:
        for i in range(1, len(curr) + 1):
          if curr[:i] in words:
            if solve(curr[i:]):
              memo[curr] = True
        if curr not in memo:
          memo[curr] = False
      return memo[curr]

    return solve(s)
