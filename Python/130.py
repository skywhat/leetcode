class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        m = len(board)
        if m == 0:
            return
        n = len(board[0])
        for i in range(m):
            if board[i][0] == "O":
                self.flipToN(board, i, 0)
            if board[i][n-1] == "O":
                self.flipToN(board, i, n-1)
        
        for i in range(n):
            if board[0][i] == "O":
                self.flipToN(board, 0, i)
            if board[m-1][i] == "O":
                self.flipToN(board, m-1, i)
                
        for i in range(m):
            for j in range(n):
                if board[i][j] == "O":
                    board[i][j] = "X"
        
        for i in range(m):
            for j in range(n):
                if board[i][j] == "N":
                    board[i][j] = "O"
                    
    def flipToN(self, board, i, j):
        if board[i][j] == "O":
            board[i][j] = "N"
            dr = [[-1, 0], [1, 0], [0, -1], [0, 1]]
            for d in dr:
                x, y = d[0]+i, d[1]+j
                if x>=0 and x<len(board) and y>=0 and y<len(board[0]):
                    self.flipToN(board, x, y)
        
