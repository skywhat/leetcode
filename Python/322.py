class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        dp = [2**32]*(amount+1)
        dp[0] = 0
        for i in range(amount+1):
            for c in coins:
                if i-c>=0:
                    dp[i] = min(dp[i], dp[i-c]+1)
        return dp[amount] if dp[amount] != 2**32 else -1
