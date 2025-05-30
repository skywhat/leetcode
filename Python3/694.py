class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        shapeset = set()
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    shape = []
                    self.dfs(grid, m, n, i, j, i, j, shape)
                    shapeset.add(tuple(shape))
        return len(shapeset)

    def dfs(self, grid, m, n, start_i, start_j, i, j, shape):
        relative_pos = (i-start_i, j-start_j)
        shape.append(relative_pos)
        grid[i][j] = 0
        for x, y in [[i-1, j], [i+1, j], [i, j-1], [i, j+1]]:
            if x<0 or x>=m or y<0 or y>=n or grid[x][y] == 0:
                continue
            self.dfs(grid, m, n, start_i, start_j, x, y, shape)
