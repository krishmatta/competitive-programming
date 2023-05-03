class Solution:
  def subsets(self, nums: List[int]) -> List[List[int]]:
    ret = []
    def solve(curr, i):
      if i >= len(nums):
        ret.append(curr)
        return
      solve(curr + [nums[i]], i + 1)
      solve(curr, i + 1)
    solve([], 0)
    return ret
