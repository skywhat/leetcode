class Solution:
    def minimumOperationsToWriteY(self, grid: List[List[int]]) -> int:
        res = float('inf')
        for i in range(3):
            for j in range(3):
                if i!=j:
                    res = min(res, self.solve(grid, i, j))
        return res

    def solve(self, grid, isY, notY):
        n = len(grid)
        op = 0
        for i in range(n):
            for j in range(n):
                if (i <= n//2 and (i==j or i+j==n-1)) or (i> n//2 and j==n//2):
                    if grid[i][j] != isY:
                        op +=1
                else:
                    if grid[i][j] != notY:
                        op +=1
        return op
