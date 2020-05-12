class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0
        n, minP = len(prices), prices[0]
        first = [0]*n
        for i in range(1, len(prices)):
            first[i] = max(first[i-1], prices[i] - minP)
            minP = min(minP, prices[i])
        
        res, maxP = first[n-1], prices[n-1]
        for i in range(n-1, 0, -1):
            res = max(res, first[i-1] + maxP-prices[i])
            maxP = max(maxP, prices[i])
        return res
