class TrieNode(object):
    def __init__(self):
        self.have = False
        self.next = [None]*26
        
class WordDictionary(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()
        

    def addWord(self, word):
        """
        Adds a word into the data structure.
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
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        return self.searchStartFromNode(self.root, word)
    
    def searchStartFromNode(self, root, word):
        if root == None:
            return False
        cur = root
        for i in range(len(word)):
            if word[i].isalpha():
                ind = ord(word[i]) - ord('a')
                if cur.next[ind] == None:
                    return False
                cur = cur.next[ind]
            elif word[i] == ".":
                for j in range(26):
                    if self.searchStartFromNode(cur.next[j], word[i+1:]):
                        return True
                return False    
        return cur.have
        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
