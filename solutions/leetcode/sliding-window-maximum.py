from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq = deque()
        i = 0
        while i < k:
            while dq and nums[dq[-1]] < nums[i]:
                dq.pop()
            dq.append(i)
            i += 1
        ret = [nums[dq[0]]]
        while i < len(nums):
            while dq and i - dq[0] >= k:
                dq.popleft()
            while dq and nums[dq[-1]] < nums[i]:
                dq.pop()
            dq.append(i)
            ret.append(nums[dq[0]])
            i += 1
        return ret
