class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        self.generate(0, 0, n, "", res)
        return res
    
    def generate(self, left, right, n, s, res):
        if left > n:
            return
        if left == n and right == n:
            res.append(s)
            return
        if left > right:
            self.generate(left, right+1, n, s+")", res)
        self.generate(left+1, right, n, s+"(", res)
