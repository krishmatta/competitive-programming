class Solution:
    def minIncrements(self, n: int, cost: List[int]) -> int:
        def solve(i):
            if i not in dp:
                if 2 * i > len(cost):
                    return (0, cost[i - 1])
                lc, ls = solve(2 * i)
                rc, rs = solve(2 * i + 1)
                ms = max(ls, rs)
                dp[i] = (lc + rc + (ms - ls) + (ms - rs), ms + cost[i - 1])
        return solve(1)[0]
