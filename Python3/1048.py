class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words = sorted(words, key=len)
        dp = defaultdict(int)
        res = 1
        for word in words:
            for i in range(len(word)):
                dp[word] = max(dp[word], dp[word[:i]+word[i+1:]]+1)
            res = max(res, dp[word])
        return res
