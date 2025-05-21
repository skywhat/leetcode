class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dist = [[0]*n for _ in range(m)]
        to_be_visited = 0

        # traverse from every hourse to empty land
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    self.bfs(grid, dist, i, j, m, n, to_be_visited)
                    to_be_visited -=1
        
        # up to this, to_be_visited are the land can be reached by every house
        # find the minimum distance among these.
        minDist = float('inf')
        for i in range(m):
            for j in range(n):
                if grid[i][j] == to_be_visited:
                    minDist = min(minDist, dist[i][j])
        return minDist if minDist != float('inf') else -1
    
    def bfs(self, grid, dist, i, j, m, n, to_be_visited):
        q = deque()
        q.append((i, j))
        step = 0
        while q:
            size = len(q)
            for _ in range(size):
                x, y = q.popleft()
                dist[x][y] += step
                for xx, yy in [[x-1, y],[x+1, y], [x, y-1], [x, y+1]]:
                    if xx>=0 and xx<m and yy>=0 and yy<n and grid[xx][yy] == to_be_visited:
                        q.append((xx, yy))
                        # minus one to make it to be visited by next bfs search.
                        grid[xx][yy] -=1
            step +=1
        
        
