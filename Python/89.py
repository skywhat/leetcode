'''
when n = 3, we can get the result based on n = 2.
00,01,11,10 -> (000,001,011,010 ) (110,111,101,100)
the middle two numbers only diff at the highest bit, while the rest numbers of part two are exactly symmetric of part one.

'''

class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        res = [0]
        if n == 0:
            return res
        for i in range(n):
            l = res[:]
            for j in range(len(l)-1, -1, -1):
                res.append(l[j]+2**i)
        return res
                
