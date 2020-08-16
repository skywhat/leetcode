class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        if n <=1:
            return 0
        if n == 2:
            return max(0, prices[1]-prices[0])
        buy = [0]*n
        buy[0] = -prices[0]
        buy[1] = max(buy[0], -prices[1])
        sell = [0]*n
        sell[1] = max(0, prices[1]-prices[0])
        for i in range(2, n):
            sell[i] = max(sell[i-1], buy[i-1] + prices[i])
            buy[i] = max(buy[i-1], sell[i-2] - prices[i])
        return sell[-1]
