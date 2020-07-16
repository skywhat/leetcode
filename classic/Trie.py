class TrieNode(object):
    def __init__(self):
        self.have = False
        self.next = [None]*26

class Trie(object):
    def __init__(self):
        self.root = TrieNode()

    def insertNode(self, word):
        cur = self.root
        for c in word:
            ind = ord(c) - ord('a')
            if cur.next[ind] == None:
                cur.next[ind] = TrieNode()
            cur = cur.next[ind]
        cur.have = True

    def searchWord(self, word):
        cur = self.root
        for c in word:
            ind = ord(c) - ord('a')
            if cur.next[ind] == None:
                return False
            cur = cur.next[ind]
        return cur.have

    def startWithPrefix(self, prefix):
        cur = self.root
        for c in prefix:
            ind = ord(c) - ord('a')
            if cur.next[ind] == None:
                return False
            cur = cur.next[ind]
        return True


if __name__ == "__main__":
    t = Trie()
    t.insertNode("hello")
    print t.searchWord("hello")
    print t.searchWord("hell")
    print t.startWithPrefix("hel")
