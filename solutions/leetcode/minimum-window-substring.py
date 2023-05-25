class Solution:
  def minWindow(self, s: str, t: str) -> str:
    t_count = {}
    for letter in t:
      if letter not in t_count:
        t_count[letter] = 0
      t_count[letter] += 1

    curr_count = {}
    ret = ""
    l, r = 0, 0
    while l <= r:
      found = True
      for letter in t_count:
        if letter not in curr_count:
          found = False
        elif curr_count[letter] < t_count[letter]:
          found = False
      if found:
        if ret == "":
          ret = s[l:r]
        elif len(s[l:r]) < len(ret):
          ret = s[l:r]
        curr_count[s[l]] -= 1
        l += 1
      else:
        if r == len(s):
          break
        else:
          if s[r] not in curr_count:
            curr_count[s[r]] = 0
          curr_count[s[r]] += 1
          r += 1
    return ret
