class Solution(object):
    def shortestPath(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        q = collections.deque()
        start = [0, 0, k]
        visited = set([(0, 0, k)])
        q.append(start)
        step = 0
        while q:
            qs = len(q)
            for i in range(qs):
                pos = q.popleft()
                if pos[0] == m-1 and pos[1] == n-1:
                    return step
                for d in [[-1, 0], [1, 0], [0, 1], [0, -1]]:
                    x, y = pos[0]+d[0], pos[1]+d[1]
                    if x<0 or x>=m or y<0 or y>=n:
                        continue

                    if grid[x][y] == 0 and (x, y, pos[2]) not in visited:
                        q.append([x, y, pos[2]])
                        visited.add((x, y, pos[2]))
                    elif pos[2] >=1 and (x, y, pos[2]-1) not in visited:
                        q.append([x, y, pos[2]-1])
                        visited.add((x, y, pos[2]-1))
            step+=1
        return -1

#optimize by check if k is large enough to have a Manhattan distance.
class Solution(object):
    def shortestPath(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        if k>=(m+n-3):
            return m+n-2
        q = collections.deque()
        start = [0, 0, k]
        visited = set([(0, 0, k)])
        q.append(start)
        step = 0
        while q:
            qs = len(q)
            for i in range(qs):
                pos = q.popleft()
                if pos[0] == m-1 and pos[1] == n-1:
                    return step
                for d in [[-1, 0], [1, 0], [0, 1], [0, -1]]:
                    x, y = pos[0]+d[0], pos[1]+d[1]
                    if x<0 or x>=m or y<0 or y>=n:
                        continue

                    if grid[x][y] == 0 and (x, y, pos[2]) not in visited:
                        q.append([x, y, pos[2]])
                        visited.add((x, y, pos[2]))
                    elif pos[2] >=1 and (x, y, pos[2]-1) not in visited:
                        q.append([x, y, pos[2]-1])
                        visited.add((x, y, pos[2]-1))
            step+=1
        return -1




