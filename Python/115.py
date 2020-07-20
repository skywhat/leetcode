# recursion + memoization.
class Solution(object):
    def __init__(self):
        self.memo = {}
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        i, j = len(s), len(t)
        if j == 0:
            return 1
        if i == 0:
            return 0
        if (i-1,j) in self.memo:
            t1 = self.memo[i-1, j]
        else:
            t1 = self.numDistinct(s[:-1], t)
            self.memo[i-1, j] = t1
            
        if s[-1] != t[-1]:
            return t1
        
        if (i-1, j-1) in self.memo:
            t2 = self.memo[i-1, j-1]
        else:
            t2 = self.numDistinct(s[:-1], t[:-1])
            self.memo[i-1, j-1] = t2
        return t1+t2
        

# dynamic programming.
class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        m, n = len(s), len(t)
        dp = [[0]*(n+1) for i in range(m+1)]
        for i in range(m+1):
            dp[i][0] = 1
        for i in range(1, m+1):
            for j in range(1, n+1):
                if s[i-1] != t[j-1]:
                    dp[i][j] = dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
        return dp[m][n]
