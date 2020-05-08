class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        cnt = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1":
                    self.dfs(grid, i, j)
                    cnt +=1
        return cnt
        
    def dfs(self, grid, i, j):
        if grid[i][j] == "1":
            grid[i][j] = "0"
            drs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
            for d in drs:
                x, y = d[0] + i, d[1] + j
                if x >= 0 and x<len(grid) and y >=0 and y<len(grid[0]):
                    self.dfs(grid, x, y)
