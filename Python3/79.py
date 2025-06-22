class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0] and self.search(board, i, j, 0, word, m, n):
                    return True
        return False
    

    def search(self, board, i, j, pos, word, m, n):
        if pos >= len(word):
            return True
        if i<0 or i>=m or j<0 or j>=n or board[i][j] != word[pos]:
            return False
        backup = board[i][j]
        board[i][j] = '#'

        for p, q in [[i-1, j], [i+1, j], [i, j-1], [i, j+1]]:
            if self.search(board, p, q, pos+1, word, m, n):
                return True
        board[i][j] = backup
        return False

