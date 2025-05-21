class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        EMPTY = 2147483647
        q = deque()
        m, n = len(rooms), len(rooms[0])
        for i in range(m):
            for j in range(n):
                if rooms[i][j] == 0:
                    q.append((i, j))
    
        dist = 0
        while q:
            size = len(q)
            for _ in range(size):
                x, y = q.popleft()
                if rooms[x][y] > dist:
                    rooms[x][y] = dist
                for xi, yi in [[x-1, y],[x+1,y],[x,y+1],[x,y-1]]:
                    if xi<0 or xi>=m or yi<0 or yi>=n or rooms[xi][yi] != EMPTY:
                        continue
                    q.append((xi, yi))
            dist +=1
