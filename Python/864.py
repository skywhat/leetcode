# using tuple as the state.
class Solution(object):
    def shortestPathAllKeys(self, grid):
        """
        :type grid: List[str]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        all_keys = [0]*6
        start_i = start_j = 0
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "@":
                    start_i, start_j = i, j
                elif grid[i][j].islower():
                    idx = ord(grid[i][j]) - ord('a')
                    all_keys[idx] = 1
        all_keys = tuple(all_keys)
        
        visited = set()
        q = deque()
        q.append((start_i, start_j, tuple([0]*6)))
        visited.add((start_i, start_j, tuple([0]*6)))
        step = 0
        while q:
            qlen = len(q)
            for _ in range(qlen):
                i, j, keys = q.popleft()
                for d in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
                    x, y = d[0]+i, d[1]+j
                    if x<0 or x>=m or y<0 or y>=n:
                        continue
                    if grid[i][j] == "#":
                        continue
                    if grid[i][j].isupper() and keys[ord(grid[i][j]) - ord('A')] != 1:
                        continue
                    keys = list(keys)
                    if grid[i][j].islower():
                        idx = ord(grid[i][j]) - ord('a')
                        keys[idx] = 1
                    keys = tuple(keys)
                    if keys == all_keys:
                        return step
                    if (x, y, keys) in visited:
                        continue
                    q.append((x, y, keys))
                    visited.add((x, y, keys))
            step +=1
        return -1

# using bit as the state
class Solution(object):
    def shortestPathAllKeys(self, grid):
        """
        :type grid: List[str]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        all_keys = 0
        start_i = start_j = 0

        for i in range(m):
            for j in range(n):
                if grid[i][j] == "@":
                    start_i, start_j = i, j
                elif grid[i][j].islower():
                    idx = ord(grid[i][j]) - ord('a')
                    all_keys |= 1<<idx

        visited = set()
        q = deque()
        q.append((start_i, start_j, 0))
        visited.add((start_i, start_j, 0))
        step = 0
        while q:
            qlen = len(q)
            for _ in range(qlen):
                i, j, keys = q.popleft()
                for d in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
                    x, y = d[0]+i, d[1]+j
                    if x<0 or x>=m or y<0 or y>=n:
                        continue
                    if grid[i][j] == "#":
                        continue
                    if grid[i][j].isupper() and ((1<< (ord(grid[i][j]) - ord('A')))&keys) == 0:
                        continue
                    if grid[i][j].islower():
                        idx = ord(grid[i][j]) - ord('a')
                        keys |= 1 << idx
                    if keys == all_keys:
                        return step
                    if (x, y, keys) in visited:
                        continue
                    q.append((x, y, keys))
                    visited.add((x, y, keys))
            step +=1
        return -1
