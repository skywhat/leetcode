class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        m, n = len(boxGrid), len(boxGrid[0])

        for i in range(m):
            empty = n-1
            for j in range(n-1, -1, -1):
                if boxGrid[i][j] == "*":
                    empty = j -1
                elif boxGrid[i][j] == "#":
                    boxGrid[i][j] = "."
                    boxGrid[i][empty] = "#"
                    empty -=1
        
        newBox = [["."]*m for _ in range(n)]

        # m = 2, n = 4
        # newBox[1][1] = boxGrid[0][1]
        # newBox[2][1] = boxGrid[0][2]
        # newBox[3][1] = boxGrid[0][3]
        for i in range(n):
            for j in range(m):
                newBox[i][j] = boxGrid[m-j-1][i]
        
        return newBox
