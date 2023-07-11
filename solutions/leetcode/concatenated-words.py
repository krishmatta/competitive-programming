class Solution:
  def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
    words = set(words)
    dp = {}
    ret = []
      
    def solve(word, start):
      if not start:
        if word in words:
          return 0
      if word not in dp:
        ret = -1
        for i in range(1, len(word)):
          if word[:i] in words:
            lower = solve(word[i:], False)
            if lower != -1:
              ret = lower + 1
              break
        dp[word] = ret
      return dp[word]

    for word in words:
      if solve(word, True) > 0:
        ret.append(word)
    return ret
