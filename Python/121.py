class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        profit = 0
        minP = prices[0]
        for i in range(1, len(prices)):
            profit = max(profit, prices[i] - minP)
            minP = min(minP, prices[i])
        return profit
