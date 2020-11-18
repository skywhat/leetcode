class Solution(object):
    def shortestDistance(self, words, word1, word2):
        """
        :type words: List[str]
        :type word1: str
        :type word2: str
        :rtype: int
        """
        i1 = i2 = -1
        minDist = len(words)
        for i, w in enumerate(words):
            if w == word1:
                i1 = i
            elif w == word2:
                i2 = i
                
            if i1 != -1 and i2 != -1:
                minDist = min(minDist, abs(i1-i2))
        return minDist
