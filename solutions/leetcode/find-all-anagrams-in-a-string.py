class Solution:
  def findAnagrams(self, s: str, p: str) -> List[int]:
    p_count = [0 for _ in range(26)]
    for x in p:
      p_count[ord(x) - ord('a')] += 1

    pfix = [[0 for _ in range(26)] for __ in range(len(s) + 1)]
    for i in range(len(s)):
      for j in range(26):
        pfix[i + 1][j] = pfix[i][j]
      pfix[i + 1][ord(s[i]) - ord('a')] += 1

    ret = []
    for i in range(len(s) - len(p) + 1):
      j = i + len(p)
      curr_count = [pfix[j][k] - pfix[i][k] for k in range(26)]
      if p_count == curr_count:
        ret.append(i)
    return ret
