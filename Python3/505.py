class Solution:
    def shortestDistance(self, maze: List[List[int]], start: List[int], destination: List[int]) -> int:
        m, n = len(maze), len(maze[0])
        pq = [(0, start[0], start[1])]
        stops = {(start[0], start[1]): 0}
        dir = [[-1, 0], [1, 0], [0, 1], [0, -1]]

        while pq:
            dist, x, y = heapq.heappop(pq)
            if [x, y] == destination:
                return dist
            for d in dir:
                next_x, next_y = x, y
                small_dist = 0
                while 0<=next_x+d[0]<m and 0<=next_y+d[1]<n and maze[next_x+d[0]][next_y+d[1]] == 0:
                    next_x += d[0]
                    next_y += d[1]
                    small_dist +=1
                if (next_x, next_y) not in stops or stops[(next_x, next_y)] > dist+small_dist:
                    stops[(next_x, next_y)] = dist + small_dist
                    heapq.heappush(pq, (dist+small_dist, next_x, next_y))
        return -1
                

