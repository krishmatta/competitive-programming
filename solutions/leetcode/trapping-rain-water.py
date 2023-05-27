class Solution:
  def helper(self, height, eq):
    greatest = [-1 for _ in range(max(height)+1)]
    for i, h in enumerate(height):
      greatest[h] = i

    for i in range(len(greatest) - 2, -1, -1):
      greatest[i] = max(greatest[i], greatest[i + 1])

    ret = 0
    curr = (-1, 0)
    curr_sub = 0
    for i, h in enumerate(height):
      if (eq and h >= curr[1]) or (not eq and h > curr[1]):
        ret += (i - curr[0] - 1) * curr[1] - curr_sub
        curr_sub = 0
        if greatest[h] > i:
          curr = (i, h)
        else:
          break
      else:
        curr_sub += h
    return ret
    
  def trap(self, height: List[int]) -> int:
    return self.helper(height, True) + self.helper(height[::-1], False)
