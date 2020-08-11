class TrieNode(object):
    def __init__(self):
        self.have = False
        self.next = [None]*26
        self.word = ""

class Solution(object):
    def __init__(self):
        self.root = TrieNode()
        
    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        self.buildTrie(words)
        m = len(board)
        if not m:
            return []
        n = len(board[0])
        res = set()
        for i in range(m):
            for j in range(n):
                self.dfs(board, i, j, res, m, n, self.root)
        return list(res)
    
    def dfs(self, board, i, j, res, m, n, cur):
        if board[i][j] == "#":
            return
        ind = ord(board[i][j]) - ord('a')
        if not cur.next[ind]:
            return
        if cur.next[ind].have:
            res.add(cur.next[ind].word)
            
        char = board[i][j]
        board[i][j] = "#"
        for d in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
            x, y = i+d[0], j+d[1]
            if x<0 or x>=m or y<0 or y>=n:
                continue
            self.dfs(board, x, y, res, m, n, cur.next[ind])
        board[i][j] = char
    
    
    def buildTrie(self, words):
        for word in words:
            self.addWord(word)
        
    
    def addWord(self, word):
        cur = self.root
        for w in word:
            ind = ord(w) - ord('a')
            if not cur.next[ind]:
                cur.next[ind] = TrieNode()
            cur = cur.next[ind]
        cur.have = True
        cur.word = word
