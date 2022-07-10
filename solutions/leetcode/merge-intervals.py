class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key = lambda x: (x[0], x[1]))
        ret = [list(intervals[0])]
        for x in range(1, len(intervals)):
            if intervals[x][0] <= ret[-1][1]:
                ret[-1][1] = max(ret[-1][1], intervals[x][1])
            else:
                ret.append(list(intervals[x]))
        return ret
