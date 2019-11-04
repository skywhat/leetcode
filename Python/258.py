class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        while True:
            res = 0
            while num != 0:
                res += num%10
                num /= 10
            if res < 10:
                return res
            num = res
