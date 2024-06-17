class Solution:
  def largestRectangleArea(self, heights: List[int]) -> int:
    heights.append(0)
    stack = [(0, 0)] # (height, index)
    ret = 0
    for i, x in enumerate(heights):
      j = i
      while stack[-1][0] > x:
        y, j = stack.pop()
        ret = max(ret, y * (i - j))
      if x > stack[-1][0]:
        stack.append((x, j))
    return ret
