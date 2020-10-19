class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        if numerator == 0:
            return "0"
        res = ""
        if (numerator<0) ^ (denominator<0):
            res += "-"
        n = abs(numerator)
        d = abs(denominator)
        
        res += str(n/d)
        n %= d
        if n % d == 0:
            return res
        res += "."
        
        ndict = {}
        
        while n:
            if n in ndict:
                pos = ndict[n]
                return res[:pos] + "(" + res[pos:] + ")"
            ndict[n] = len(res)
            n *=10
            res += str(n/d)
            n %= d
        return res
