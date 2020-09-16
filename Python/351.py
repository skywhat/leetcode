class Solution(object):
    def __init__(self):
        self.skip = [[0]*10 for _ in range(10)]
        self.skip[1][3] = self.skip[3][1] = 2
        self.skip[1][7] = self.skip[7][1] = 4
        self.skip[3][9] = self.skip[9][3] = 6
        self.skip[7][9] = self.skip[9][7] = 8
        self.skip[1][9] = self.skip[9][1] = self.skip[3][7] = self.skip[7][3] = \
        self.skip[2][8] = self.skip[8][2] = self.skip[4][6] = self.skip[6][4] = 5
        
    
    def numberOfPatterns(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        visit = [False]*10
        def dfs(start, remaining, visit):
            if remaining == 0:
                return 1
            res = 0
            visit[start] = True
            for i in range(1, 10):
                if visit[i]:
                    continue
                if self.skip[start][i] == 0 or visit[self.skip[start][i]]:
                    res += dfs(i, remaining-1, visit)
            visit[start] = False
            return res
        
        
        res = 0
        for i in range(m, n+1):
            res += dfs(1, i-1, visit)*4
            res += dfs(2, i-1, visit)*4
            res += dfs(5, i-1, visit)
        return res
