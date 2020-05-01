class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        aa = list(a)
        bb = list(b)
        res = ""
        carry = 0
        while aa or bb or carry:
            if aa:
                carry += int(aa.pop())
            if bb:
                carry += int(bb.pop())
            res = str(carry%2) + res
            carry //= 2
        return res
        
