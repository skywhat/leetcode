class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] != 0:
                    res = max(res, self.dfs(grid, i, j, m, n))
        return res

    def dfs(self, grid, i, j, m, n):
        if i<0 or i>=m or j<0 or j>=n or grid[i][j] == 0:
            return 0
        area = grid[i][j]
        grid[i][j] = 0
        for x, y in [[i-1, j], [i+1, j], [i, j-1], [i, j+1]]:
            area += self.dfs(grid, x, y, m, n)
        return area
