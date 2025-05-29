class Solution:
    def findShortestWay(self, maze: List[List[int]], ball: List[int], hole: List[int]) -> str:
        m, n = len(maze), len(maze[0])
        pq = [(0, "", ball[0], ball[1])]
        stops = {(ball[0], ball[1]): (0, "")}
        dirs = [[-1,0, 'u'],[1,0,'d'],[0,1,'r'],[0,-1,'l']]

        while pq:
            dist, pattern, cur_x, cur_y = heapq.heappop(pq)
            if [cur_x, cur_y] == hole:
                return pattern
            for i, j, move in dirs:
                small_dist = 0
                x, y = cur_x, cur_y
                while 0<=x+i<m and 0<=y+j<n and maze[x+i][y+j] == 0:
                    x +=i
                    y +=j
                    small_dist +=1
                    if [x, y] == hole:
                        break
                if (x, y) not in stops or stops[(x, y)] > (dist+small_dist, pattern+move):
                    stops[(x, y)] = (dist+small_dist, pattern+move)
                    heapq.heappush(pq, (dist+small_dist, pattern+move, x, y))

        return "impossible"
