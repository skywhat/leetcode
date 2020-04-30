class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        if num1 == "0" or num2 == "0":
            return "0"
        m, n = len(num1), len(num2)
        res = [0]*(m+n)
        for i in range(m-1, -1,-1):
            carry = 0
            for j in range(n-1, -1, -1):
                unit = int(num1[i])*int(num2[j]) + carry
                carry = (res[i+j+1]+unit)/10
                res[i+j+1] = (res[i+j+1] + unit)%10
            res[i] += carry
        
        s = "".join(map(str, res))
        for i in range(len(s)):
            if s[i] != "0":
                return s[i:]
        return ""
