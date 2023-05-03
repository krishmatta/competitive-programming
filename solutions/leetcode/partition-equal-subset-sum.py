class Solution:
  def canPartition(self, nums: List[int]) -> bool:
    memo = {}
    tot = sum(nums)
    if tot % 2 == 1:
      return False
    aim = tot // 2

    def solve(curr, i):
      if curr == 0:
        return True
      if curr < 0 or i > len(nums):
        return False
      if (curr, i) not in memo:
        memo[(curr, i)] = solve(curr - nums[i], i + 1) or solve(curr, i + 1)
      return memo[(curr, i)]

    return solve(aim, 0)
