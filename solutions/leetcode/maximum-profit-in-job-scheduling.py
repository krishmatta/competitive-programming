from bisect import bisect_left

class Solution:
  def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
    jobs = [(x, y, z) for x, y, z in zip(startTime, endTime, profit)]
    jobs = sorted(jobs)

    dp = {}

    def helper(i):
      if i == None or i >= len(jobs):
        return 0
      if i not in dp:
        idx = bisect_left(jobs, jobs[i][1], key=lambda x: x[0])
        dp[i] = max(helper(idx) + jobs[i][2], helper(i + 1))
      return dp[i]
    return helper(0)
