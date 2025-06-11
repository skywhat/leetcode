class Solution:
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        uf = list(range(m*n))
        grid = [[0]*n for _ in range(m)]

        cnt = 0
        res = []
        for i, j in positions:
            if grid[i][j]:
                res.append(cnt)
                continue
            cur = i*n+j
            cur_root = self.find(uf, cur)
            cnt +=1
            grid[i][j] = 1
            for x, y in [[i-1,j],[i+1,j],[i,j-1],[i,j+1]]:
                if x<0 or x>=m or y<0 or y>=n or grid[x][y] == 0:
                    continue
                ne = x*n+y
                ne_root = self.find(uf, ne)
                if cur_root != ne_root:
                    # current position is the central position to connect nearby islands
                    # so use cur_root as the root of the nearby island.
                    uf[ne_root] = cur_root
                    cnt -=1
            
            res.append(cnt)
        return res

    

    def find(self, uf, p):
        if uf[p] != p:
            uf[p] = self.find(uf, uf[p])
        return uf[p]