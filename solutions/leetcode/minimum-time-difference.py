class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        def convToMin(s):
            hh, mm = [int(x) for x in s.split(":")]
            return hh * 60 + mm
        times = [convToMin(x) for x in timePoints]
        times = sorted(times)
        ret = times[0] + convToMin("24:00") - times[-1]
        for i in range(1, len(times)):
            ret = min(ret, times[i] - times[i - 1])
        return ret
