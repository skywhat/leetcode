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

    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        for word in products:
            self._insert(word)
        
        res = []
        cur = self.root
        for c in searchWord:
            idx = ord(c) - ord('a')
            if not cur.next[idx]:
                break
            cur = cur.next[idx]
            temp = []
            self._search3(cur, temp)
            res.append(temp)
        while len(res) < len(searchWord):
            res.append([])
        return res
    
    def _search3(self, cur, temp):
        if len(temp) == 3:
            return
        if cur.word != "":
            temp.append(cur.word)
        for i in range(26):
            if cur.next[i]:
                self._search3(cur.next[i], temp)
                if len(temp) == 3:
                    return
