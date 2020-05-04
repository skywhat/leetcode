from collections import deque
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        q = deque()
        q.append(beginWord)
        words = set(wordList)
        dist = 1
        while len(q) != 0:
            n = len(q)
            for i in range(n):
                w = q.popleft()
                if w == endWord:
                    return dist
                self.addNextWord(w, words, q)
            dist +=1
        return 0
    
    def addNextWord(self, begin, words, q):
        for i in range(len(begin)):
            x = begin[i]
            for j in range(26):
                ch = chr(ord('a')+j)
                if ch == x:
                    continue
                begin = begin[:i] + ch + begin[i+1:]
                if begin in words:
                    q.append(begin)
                    words.discard(begin)
            begin = begin[:i] + x + begin[i+1:]
        
