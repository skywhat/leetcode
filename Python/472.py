DFS
it usually takes 300 ms

class Solution(object):
    def findAllConcatenatedWordsInADict(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        ws = set()
        words = sorted(words, key= lambda w:len(w))
        res = []
        def dfs(w):
            if w in ws:
                return True
            for i in range(1, len(w)):
                if w[:i] in ws and dfs(w[i:]):
                    return True
            return False
        
        for k in range(len(words)):
            if dfs(words[k]):
                res.append(words[k])
            ws.add(words[k])
        return res
DP
it usually takes 2000ms

class Solution(object):
    def findAllConcatenatedWordsInADict(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        ws = set()
        words = sorted(words, key= lambda w:len(w))
        res = []
        for k in range(len(words)):
            n = len(words[k])
            dp = [False]*(n+1)
            dp[0] = True
            
            for i in range(1, n+1):
                for j in range(i-1, -1, -1):
                    if dp[j] and (i-j < n) and words[k][j:i] in ws:
                        dp[i] = True
                        break
            if n!=0 and dp[n]:
                res.append(words[k])
            ws.add(words[k])
        return res
