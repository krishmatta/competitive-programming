class Solution:
    def deleteString(self, s: str) -> int:
        dp = {}
        def solve(i):
            if i not in dp:
                ret = 1
                j = 1
                while i + 2 * j <= len(s):
                    first = s[i:i+j]
                    second = s[i+j:i+2*j]
                    if first == second:
                        ret = max(ret, 1 + solve(i + j))
                    j += 1
                dp[i] = ret
            return dp[i]
        return solve(0)
