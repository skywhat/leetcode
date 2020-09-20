#DFS
class Solution(object):
    def __init__(self):
        self.move = {1: [(0, -1), (0, 1)], 2:[(-1, 0), (1, 0)], 3:[(0, -1), (1, 0)], \
                    4:[(0, 1), (1, 0)], 5:[(0, -1), (-1, 0)], 6:[(-1, 0), (0, 1)]}

    def hasValidPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        m, n = len(grid), len(grid[0])
        visit = [[False]*n for _ in range(m)]
        return self.dfs(0, 0, visit, grid, m, n)

    def dfs(self, i, j, visit, grid, m, n):
        if i == m-1 and j == n-1:
            return True

        visit[i][j] = True
        for pos in self.move[grid[i][j]]:
            x, y = i+pos[0], j+pos[1]
            if x<0 or x>=m or y<0 or y>=n  or visit[x][y]:
                continue
            a, b = self.move[grid[i][j]], self.move[grid[x][y]]
            movable = False
            for p in b:
                if x+p[0] == i and y+p[1] == j:
                    movable = True
                    break
            if movable and self.dfs(x, y, visit, grid, m, n):
                return True

        visit[i][j] = False
        return False



class Solution(object):
    def __init__(self):
        self.move = {1: [(0, -1), (0, 1)], 2:[(-1, 0), (1, 0)], 3:[(0, -1), (1, 0)], \
                    4:[(0, 1), (1, 0)], 5:[(0, -1), (-1, 0)], 6:[(-1, 0), (0, 1)]}
    
    def hasValidPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        m, n = len(grid), len(grid[0])
        visit = [[False]*n for _ in range(m)]
        q = deque([(0, 0)])
        
        while q:
            i, j = q.popleft()
            visit[i][j] = True
            for p in self.move[grid[i][j]]:
                x, y = i+p[0], j+p[1]
                if x<0 or x>=m or y<0 or y>=n or visit[x][y]:
                    continue
                a, b = self.move[grid[i][j]], self.move[grid[x][y]]
                movable = False
                for back in b:
                    if back[0]+x == i and back[1]+y == j:
                        movable = True
                        break
                if movable:
                    q.append((x, y))
        return visit[m-1][n-1]
