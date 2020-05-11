class TrieNode(object):
    def __init__(self):
        self.have = False
        self.next = [None]*26

class Trie(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()
        

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: None
        """
        cur = self.root
        for c in word:
            ind = ord(c) - ord('a')
            if cur.next[ind] == None:
                cur.next[ind] = TrieNode()
            cur = cur.next[ind]
        cur.have = True
        
        

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        cur = self.root
        for c in word:
            ind = ord(c) - ord('a')
            if cur.next[ind] == None:
                return False
            cur = cur.next[ind]
        return cur.have
        

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        cur = self.root
        for c in prefix:
            ind = ord(c) - ord('a')
            if cur.next[ind] == None:
                return False
            cur = cur.next[ind]
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
