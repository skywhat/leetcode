class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        wordSet = set(wordList)
        q = collections.deque()
        q.append(beginWord)
        step = 0
        while q:
            size = len(q)
            step +=1
            for _ in range(size):
                word = q.popleft()
                if word == endWord:
                    return step
                for i in range(len(word)):
                    for k in range(26):
                        candidate = word[:i] + chr(ord('a')+k) + word[i+1:]
                        if candidate in wordSet:
                            q.append(candidate)
                            wordSet.discard(candidate)
        
        return 0
