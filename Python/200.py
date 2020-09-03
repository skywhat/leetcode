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

#union find 
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
        uf = [0]*(m*n)
        cnt = 0
        for i in range(m):
            for j in range(n):
                uf[i*n+j] = i*n + j
                if grid[i][j] == "1":
                    cnt +=1

        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1":
                    cur = i*n+j
                    for d in [[-1, 0], [1, 0], [0, 1], [0, -1]]:
                        x, y = i+d[0], j+d[1]
                        if x<0 or x>=m or y<0 or y>=n or grid[x][y] == "0":
                            continue
                        np = x*n+y
                        cur_root = self.find(uf, cur)
                        np_root = self.find(uf, np)
                        if cur_root != np_root:
                            uf[np_root] = cur_root
                            cnt -=1

        return cnt

    def find(self, uf, p):
        while uf[p] != p:
            uf[p] = uf[uf[p]]
            p = uf[p]
        return p
