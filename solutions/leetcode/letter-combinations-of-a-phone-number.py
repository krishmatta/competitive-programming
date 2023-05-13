class Solution:
  def letterCombinations(self, digits: str) -> List[str]:
    letters = {
      "2": "abc",
      "3": "def",
      "4": "ghi",
      "5": "jkl",
      "6": "mno",
      "7": "pqrs",
      "8": "tuv",
      "9": "wxyz",
    }
    
    ret = []
    def solve(i, acc):
      if i >= len(digits):
        if len(acc):
          ret.append(acc)
        return
      for x in letters[digits[i]]:
        solve(i + 1, acc + x)
    solve(0, "")
    return ret
