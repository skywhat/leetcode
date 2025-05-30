class Solution:
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        uf = [i for i in range(m*n)]
        grid = [[0]*n for _ in range(m)]

        res = []
        cnt = 0
        for x, y in positions:
            cur = x*n + y
            if grid[x][y]:
                res.append(cnt)
                continue
            cnt+=1
            grid[x][y] = 1
            for p, q in [[x-1,y],[x+1,y],[x,y-1],[x,y+1]]:
                if p<0 or p>=m or q<0 or q>=n or grid[p][q] == 0:
                    continue
                nb = self.find(uf, p*n+q)
                cur_root = self.find(uf, cur)
                if nb != cur_root:
                    uf[cur_root] = nb
                    cnt -=1
            res.append(cnt)
        return res

    def find(self, uf, p):
        if uf[p] != p:
            uf[p] = self.find(uf, uf[p])
        return uf[p]
