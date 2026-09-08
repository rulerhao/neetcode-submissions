class Solution:
    def climbStairs(self, n: int) -> int:
        # Solution 1 -- Backtracking, Decision tree, O(2^n)
        ## 5: 1+1+1+1+1, 1+1+1+2, 1+1+2+1, 1+2+1+1, 2+1+1+1, 1+2+2, 2+1+2, 2+2+1

        # Solution 2 -- DP Time Complexity O(n), Space Complexity O(n)
        ## 5 should be 1+4, 2+3. And the both times 
        ## 4: 1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2
        ## 3: 1+1+1, 1+2, 2+1
        ## 2: 1+1, 2
        ## 1: 1
        
        ## Because of 3 stair would be 1 stair with 2 step and 2th with 1 step. 
        ## So we can consider it as dp[i] = dp[i-1] + dp[i-2].

        if n == 0: return 0
        elif n == 1: return 1
        elif n == 2: return 2

        dp = [0] * (n + 1) ## 0..n
        dp[0] = 0
        dp[1] = 1
        dp[2] = 2
        
        for i in range(3, n + 1): ## 3..n
            dp[i] = dp[i-1] + dp[i-2]

        return dp[i]