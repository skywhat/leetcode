class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        res = 1
        cache = {}
        for i in range(m):
            for j in range(n):
                res = max(res, self.findLongest(matrix, i, j, m, n, cache))
        return res

    def findLongest(self, grid, i, j, m, n, cache):
        if (i, j) in cache:
            return cache[(i, j)]
        
        res = 1
        for x, y in [[i-1, j], [i+1, j], [i, j-1], [i, j+1]]:
            if x < 0 or x>=m or y<0 or y>=n or grid[x][y] <= grid[i][j]:
                continue
            res = max(res, self.findLongest(grid, x, y, m, n, cache) + 1)
        cache[(i, j)] = res
        return res
