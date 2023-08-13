class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        dp = {}
        def solve(i, length):
            if i >= len(nums) and (length == 0 or (length == 2 and nums[i - 1] == nums[i - 2])):
                return True
            if i >= len(nums):
                return False
            if (i, length) not in dp:
                ret = False
                if length == 0:
                    ret = ret or solve(i + 1, 1)
                if length == 1:
                    if nums[i] == nums[i - 1] + 1:
                        ret = ret or solve(i + 1, 2)
                    if nums[i] == nums[i - 1]:
                        ret = ret or solve(i + 1, 2)
                if length == 2:
                    if nums[i - 1] == nums[i - 2]:
                        ret = ret or solve(i + 1, 1)
                        if nums[i] == nums[i - 1]:
                            ret = ret or solve(i + 1, 0)
                    if nums[i - 1] == nums[i - 2] + 1 and nums[i] == nums[i - 1] + 1:
                        ret = ret or solve(i + 1, 0)
                dp[(i, length)] = ret
            return dp[(i, length)]
        return solve(0, 0)
