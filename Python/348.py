class TicTacToe(object):

    def __init__(self, n):
        """
        Initialize your data structure here.
        :type n: int
        """
        self.n = n
        self.rows = [0]*n
        self.cols = [0]*n
        self.diag1 = self.diag2 = 0
        

    def move(self, row, col, player):
        """
        Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins.
        :type row: int
        :type col: int
        :type player: int
        :rtype: int
        """
        val = 1 if player == 1 else -1
        self.rows[row] += val
        self.cols[col] += val
        if row == col:
            self.diag1 += val
        if (row+col) == (self.n-1):
            self.diag2 += val
        if abs(self.rows[row]) == self.n or abs(self.cols[col]) == self.n or abs(self.diag1) == self.n or abs(self.diag2) == self.n:
            return player
        return 0
        


# Your TicTacToe object will be instantiated and called as such:
# obj = TicTacToe(n)
# param_1 = obj.move(row,col,player)
