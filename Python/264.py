class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 0
        dp = [0]*n
        dp[0] = 1
        t2 = t3 = t5 = 0
        for i in range(1, n):
            dp[i] = min(dp[t2]*2, min(dp[t3]*3, dp[t5]*5))
            if dp[i] == dp[t2]*2:
                t2+=1
            if dp[i] == dp[t3]*3:
                t3+=1
            if dp[i] == dp[t5]*5:
                t5+=1
        return dp[n-1]
