class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        s = []
        to_cover = 0
        for i in range(n + 1):
            if ranges[i] == 0:
                continue
            while s and i - ranges[i] <= (s[-1][1]) and (i + ranges[i] >= s[-1][0] + ranges[s[-1][0]]):
                _, to_cover = s.pop()
            if to_cover < n and (i - ranges[i] <= to_cover and to_cover <= i + ranges[i]):
                s.append((i, to_cover))
                to_cover = i + ranges[i]
        if to_cover >= n:
            return len(s)
        return -1
