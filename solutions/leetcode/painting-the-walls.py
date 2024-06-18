class Solution:
    def paintWalls(self, cost: List[int], time: List[int]) -> int:
        dp = [int(1e9) if i else 0 for i in range(len(cost) + 1)]
        for i in range(len(cost)):
            dp = [min(dp[j], dp[max(0, j - time[i] - 1)] + cost[i]) for j in range(len(cost) + 1)]
        return dp[len(cost)]
