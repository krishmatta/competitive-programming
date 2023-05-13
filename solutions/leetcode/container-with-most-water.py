class Solution:
  def maxArea(self, height: List[int]) -> int:
    ret = 0
    l, r = 0, len(height) - 1
    while l <= r:
      area = (r - l) * min(height[r], height[l])
      ret = max(ret, area)
      if height[l] < height[r]:
        l += 1
      else:
        r -= 1
    return ret
