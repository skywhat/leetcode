# BFS

class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        orange = 0
        q = deque()

        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    q.append((i, j))
                    orange +=1
                elif grid[i][j] == 1:
                    orange +=1

        if orange == 0:
            return 0

        minute = -1
        cnt = 0
        while q:
            qlen = len(q)
            for _ in range(qlen):
                i, j = q.popleft()
                cnt +=1

                for d in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
                    x, y = d[0]+i, d[1]+j
                    if x<0 or x>=m or y<0 or y>=n or grid[x][y] == 0 or grid[x][y] == 2:
                        continue
                    q.append((x, y))
                    grid[x][y] = 2
            minute +=1
        return minute if cnt == orange else -1
