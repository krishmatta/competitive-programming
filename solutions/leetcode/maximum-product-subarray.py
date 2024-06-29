class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ret = nums[0]
        mx = nums[0]
        mn = nums[0]
        for x in nums[1:]:
            a = mx * x
            b = mn * x
            mx = max(x, a, b)
            mn = min(x, a, b)
            ret = max(ret, mx)
        return ret
