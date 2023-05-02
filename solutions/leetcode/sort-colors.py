class Solution:
  def sortColors(self, nums: List[int]) -> None:
    count = {i: 0 for i in range(3)}
    for num in nums:
      count[num] += 1

    for i in range(len(nums)):
      for j in range(3):
        if count[j] > 0:
          nums[i] = j
          count[j] -= 1
          break
