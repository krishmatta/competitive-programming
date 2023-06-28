class Solution:
  def firstMissingPositive(self, nums: List[int]) -> int:
    for i in range(len(nums)):
      while nums[i] > 0 and nums[i] <= len(nums) and nums[i] - 1 != i:
        if nums[nums[i] - 1] == nums[i]:
          break
        tmp = nums[nums[i] - 1]
        nums[nums[i] - 1] = nums[i]
        nums[i] = tmp

    for i, x in enumerate(nums):
      if i != x - 1:
        return i + 1
    return len(nums) + 1
