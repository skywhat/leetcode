class Solution:
    def minTotalDistance(self, grid: List[List[int]]) -> int:
        rows = []
        cols = []
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    rows.append(i)
                    cols.append(j)
        rows = sorted(rows)
        cols = sorted(cols)
        total_dist = 0
        i, j = 0, len(rows)-1
        while i<j:
            total_dist += rows[j]-rows[i]
            i+=1
            j-=1
        i, j = 0, len(cols)-1
        while i<j:
            total_dist += cols[j]-cols[i]
            i+=1
            j-=1
        return total_dist
