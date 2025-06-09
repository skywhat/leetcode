class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        m, n = len(heightMap), len(heightMap[0])
        h = []
        visited = [[False]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i == 0 or i == m-1 or j == 0 or j == n-1:
                    heapq.heappush(h, (heightMap[i][j], i, j))
                    visited[i][j] = True

        res = 0
        maxH = 0
        while h:
            height, i, j = heapq.heappop(h)
            if height > maxH:
                maxH = height
            else:
                res += maxH - height
            for x, y in [[i-1, j], [i+1, j], [i, j-1], [i, j+1]]:
                if x<0 or x>=m or y<0 or y>=n or visited[x][y]:
                    continue
                heapq.heappush(h, (heightMap[x][y], x, y))
                visited[x][y] = True
        return res
            
