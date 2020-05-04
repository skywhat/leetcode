from collections import deque
class Solution(object):
    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """
        paths = deque()
        paths.append([beginWord])
        res = []
        words = set(wordList)
        level, minLevel = 1, len(words)
        levelWords = set()
        
        while paths:
            cur = paths.popleft()
            if len(cur) > level:
                level = len(cur)
                words = words - levelWords
                if level > minLevel:
                    break
            begin = cur[-1]
            for i in range(len(begin)):
                x = begin[i]
                for j in range(26):
                    ch = chr(ord('a')+j)
                    begin = begin[:i]+ch+begin[i+1:]
                    if begin in words:
                        levelWords.add(begin)
                        new_path = cur + [begin]
                        paths.append(new_path)
                        if begin == endWord:
                            minLevel = level
                            res.append(new_path)
                begin = begin[:i]+x+begin[i+1:]
            
        return res
