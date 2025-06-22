class Solution:
    class TrieNode:
        def __init__(self):
            self.next = [None]*26
            self.word = ""
    
    def __init__(self):
        self.root = self.TrieNode()

    def _insert(self, word):
        cur = self.root
        for c in word:
            idx = ord(c) - ord('a')
            if not cur.next[idx]:
                cur.next[idx] = self.TrieNode()
            cur = cur.next[idx]
        cur.word = word
    
    # use # to mark visited position
    def _search(self, board, i, j, res, m, n, cur):
        if i<0 or i>=m or j<0 or j>=n or board[i][j] == '#' or not cur:
            return
        idx = ord(board[i][j]) - ord('a')
        if not cur.next[idx]:
            return
        if cur.next[idx].word != "":
            res.append(cur.next[idx].word)
            cur.next[idx].word = ""

        # prune the subtree to optimize
        canPrune = True
        for k in range(26):
            if cur.next[idx].next[k]:
                canPrune = False
                break
        if canPrune:
            cur.next[idx] = None
            return

        backup = board[i][j]
        board[i][j] = '#'
        for p, q in [[i-1, j], [i+1, j], [i, j-1], [i, j+1]]:
            self._search(board, p, q, res, m, n, cur.next[idx])
        board[i][j] = backup
        

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        for word in set(words):
            self._insert(word)
        
        res = []
        m, n = len(board), len(board[0])
        for i in range(m):
            for j in range(n):
                self._search(board, i, j, res, m, n, self.root)
        return res
