class Solution:
    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        m, n = len(maze), len(maze[0])
        visited = [[False]*n for _ in range(m)]
        return self.dfs(maze, start, destination, visited, m, n)

    def dfs(self, maze, start, destination, visited, m, n):
        if visited[start[0]][start[1]]:
            return False
        if start == destination:
            return True
        visited[start[0]][start[1]] = True
        dir = [[-1, 0], [1,0], [0,1],[0,-1]]
        for d in dir:
            x, y = start[0], start[1]
            while 0<=x+d[0]<m and 0<=y+d[1]<n and maze[x+d[0]][y+d[1]] == 0:
                x+=d[0]
                y+=d[1]
            if self.dfs(maze, [x, y], destination, visited, m, n):
                return True
        return False

