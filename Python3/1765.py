class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        m, n = len(isWater), len(isWater[0])
        q = deque()
        dist = [[m+n]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if isWater[i][j] == 1:
                    q.append((i, j))
                    dist[i][j] = 0
        
        while q:
            i, j = q.popleft()
            for x, y in [[i-1,j],[i+1,j],[i,j+1],[i,j-1]]:
                if x<0 or x>=m or y<0 or y>=n or dist[x][y] <= dist[i][j] + 1:
                    continue
                dist[x][y] = dist[i][j] + 1
                q.append((x, y))
        return dist
