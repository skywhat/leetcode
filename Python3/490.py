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
            while x>=0 and x<m and y>=0 and y<n and maze[x][y] == 0:
                x+=d[0]
                y+=d[1]
            if self.dfs(maze, [x-d[0], y-d[1]], destination, visited, m, n):
                return True
        return False

