# greedy

class Solution(object):
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        n = len(prices)
        minP = prices[0]
        res = 0
        for i in range(1, n):
            if prices[i] < minP:
                minP = prices[i]
            elif prices[i] > minP + fee:
                res += prices[i] - minP - fee
                minP = prices[i] - fee
        return res


# dp
class Solution(object):
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        n = len(prices)
        buy = [0]*n
        buy[0] = -prices[0]
        sell = [0]*n

        for i in range(1, n):
            sell[i] = max(sell[i-1], buy[i-1] + prices[i] -fee)
            buy[i] = max(sell[i-1] - prices[i], buy[i-1])
        # print sell
        # print buy
        return sell[-1]

