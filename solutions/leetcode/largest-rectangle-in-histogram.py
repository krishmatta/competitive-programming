class Solution:
  def largestRectangleArea(self, heights: List[int]) -> int:
    def helper(heights):
      s = []
      ret = []
      for height in heights:
        width = 1
        while len(s) > 0 and s[-1][1] >= height:
          w, h = s.pop()
          width += w
        s.append((width, height))
        ret.append(width * height)
      return ret
    fwd = helper(heights)
    bwd = helper(heights[::-1])[::-1]
    return max([x + y - z for x, y, z in zip(fwd, bwd, heights)])
