class Solution(object):
    def maxSatisfied(self, customers, grumpy, X):
        """
        :type customers: List[int]
        :type grumpy: List[int]
        :type X: int
        :rtype: int
        """
        satisfied = 0
        maxWinSatisfied = 0
        winSatisfied = 0
        
        for i in range(len(customers)):
            if grumpy[i] == 0:
                satisfied += customers[i]
            else:
                winSatisfied += customers[i]
            if i>=X:
                winSatisfied -= grumpy[i-X]*customers[i-X]
            maxWinSatisfied = max(maxWinSatisfied, winSatisfied)
        return satisfied + maxWinSatisfied
