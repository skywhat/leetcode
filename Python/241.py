class Solution(object):
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        if input.isdigit():
            return [int(input)]
        res = []
        for i in range(len(input)):
            if input[i] in "+-*":
                xs = self.diffWaysToCompute(input[:i])
                ys = self.diffWaysToCompute(input[i+1:])
                for x in xs:
                    for y in ys:
                        res.append(self.compute(x, y, input[i]))
        return res
    
    def compute(self, x, y, op):
        if op == "+":
            return x+y
        if op == "-":
            return x-y
        if op == "*":
            return x*y
        return 0
