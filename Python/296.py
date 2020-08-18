class Solution(object):
    def minTotalDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rows = []
        cols = []
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    rows.append(i)
        
        for j in range(n):
            for i in range(m):
                if grid[i][j] == 1:
                    cols.append(j)
        
        dist = 0
        i, j = 0, len(rows)-1
        while i<j:
            dist += rows[j]-rows[i]
            i+=1
            j-=1
        
        i, j = 0, len(cols)-1
        while i<j:
            dist += cols[j]-cols[i]
            i+=1
            j-=1
        return dist
