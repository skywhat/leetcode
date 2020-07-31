class Solution(object):
    def longestStrChain(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        words = sorted(words, key=len)
        print words
        dp = defaultdict(int)
        maxLen = 1
        for w in words:
            for i in range(len(w)):
                dp[w] = max(dp[w], dp[w[:i]+w[i+1:]]+1)
            maxLen = max(maxLen, dp[w])
        return maxLen
