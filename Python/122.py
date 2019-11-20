class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        i = 0
        profit = 0
        while i< len(prices):
            j = i+1
            while j<len(prices):
                if prices[j] >= prices[j-1]:
                    j+=1
                else:
                    break
            if prices[j-1]<=prices[i]:
                i+=1
            else:
                profit += prices[j-1]-prices[i]
            i = j
        return profit

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        profit = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i-1]:
                profit += prices[i]-prices[i-1]
        return profit
