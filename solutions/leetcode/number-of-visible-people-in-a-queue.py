from collections import deque

class Solution:
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        dq = deque()
        ret = []
        for x in heights[::-1]:
            rm = 0
            while dq and x > dq[0]:
                dq.popleft()
                rm += 1
            if dq:
                rm += 1
            ret.append(rm)
            dq.appendleft(x)
        return ret[::-1]
