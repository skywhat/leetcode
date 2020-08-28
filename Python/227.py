class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        nums = []
        op = "+"
        n = 0
        
        for i, x in enumerate(s+"+"):
            if x.isdigit():
                n = n*10 + int(x)
            elif x in "+-*/":
                if op == "+":
                    nums.append(n)
                elif op == "-":
                    nums.append(-n)
                elif op == "*":
                    nums.append(nums.pop() * n)
                elif op == "/":
                    nums.append(int(float(nums.pop()) / n))
                
                n = 0
                op = x
        print nums
        return sum(nums)



class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        nums = []
        op = "+"
        n = 0
        res = 0
        tempsum = 0

        for i, x in enumerate(s+"+"):
            if x.isdigit():
                n = n*10 + int(x)
            elif x in "+-*/":
                if op == "+":
                    res += tempsum
                    tempsum = n
                elif op == "-":
                    res += tempsum
                    tempsum = -n
                elif op == "*":
                    tempsum *= n
                elif op == "/":
                    tempsum = int(float(tempsum) / n)

                n = 0
                op = x
        return res + tempsum
