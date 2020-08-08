class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        res = [0]*(num+1)
        for i in range(1, num+1):
            res[i] = res[i&(i-1)]+1
        return res
