class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        m, n = len(dungeon), len(dungeon[0])
        need = [[2**32]*(n+1) for i in range(m+1)]
        need[m][n-1] = need[m-1][n] = 1
    
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                if dungeon[i][j] >= min(need[i+1][j], need[i][j+1]):
                    need[i][j] = 1
                else:
                    need[i][j] = min(need[i+1][j], need[i][j+1]) - dungeon[i][j]
        return need[0][0]
