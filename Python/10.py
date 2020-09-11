class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        m, n = len(s), len(p)
        dp = [[False]*(n+1) for _ in range(m+1)]
        dp[0][0] = True
        
        for i in range(2, n+1):
            dp[0][i] = dp[0][i-2] and p[i-1] == "*"
                
        for i in range(1, m+1):
            for j in range(1, n+1):
                if j>1 and p[j-1] == "*":
                    dp[i][j] = dp[i][j-2] or ((s[i-1] == p[j-2] or p[j-2] == ".") and dp[i-1][j])
                else:
                    dp[i][j] = dp[i-1][j-1] and (s[i-1] == p[j-1] or p[j-1] == ".")
        
        return dp[m][n]
