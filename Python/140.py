class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        res = []
        n = len(s)
        words = set(wordDict)
        if not n:
            return res
        dp = [False]*(n+1)
        dp[0] = True
        for i in range(1, n+1):
            for j in range(i-1, -1, -1):
                if dp[j] and s[j:i] in words:
                    dp[i] = True
                    break
        if not dp[n]:
            return res
        self.createSentence(s, words, 0, "", res, dp)
        return res
    
    def createSentence(self, s, words, pos, st, res, dp):
        for i in range(pos, len(s)):
            if dp[i+1] and s[pos:i+1] in words:
                if i+1 == len(s):
                    res.append(st+s[pos:])
                else:
                    self.createSentence(s, words, i+1, st+s[pos:i+1]+" ", res, dp)
