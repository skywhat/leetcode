class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        signs = []
        nums = []
        res = n = 0
        sign = 1
        for i, x in enumerate(s):
            if x.isdigit():
                n = n*10 + int(x)
                continue
            res = res + sign*n
            n = 0
            
            if x == "+":
                sign = 1
            elif x == "-":
                sign = -1
            elif x == "(":
                nums.append(res)
                signs.append(sign)
                sign = 1
                res = 0
            elif x == ")":
                res = nums[-1] + signs[-1]*res
                nums.pop()
                signs.pop()
                
        return res + n*sign
