class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        colors = [0, 0]
        n = len(grid)
        def findSize(i, j, color):
            if i<0 or i>=n or j<0 or j>=n or grid[i][j] != 1:
                return 0
            grid[i][j] = color
            return 1+findSize(i+1, j, color) + findSize(i-1, j, color) + \
            findSize(i, j+1, color) + findSize(i, j-1, color)
        
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    size = findSize(i, j, len(colors))
                    colors.append(size)
        
        res = 0
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    distinctSizes = set()
                    for x, y in [[i+1, j],[i-1, j], [i, j-1], [i, j+1]]:
                        if x<0 or x>=n or y<0 or y>=n or grid[x][y] == 0:
                            continue
                        distinctSizes.add(grid[x][y])
                    area = 1
                    for idx in distinctSizes:
                        area += colors[idx]
                    res = max(res, area)
        return res if res != 0 else n*n

