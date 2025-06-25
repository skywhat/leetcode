class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        self.backtracking(n, n, res, "")
        return res
    
    def backtracking(self, left, right, res, path):
        if left == 0 and right == 0:
            res.append(path)
            return
        if left > right or left < 0 or right < 0:
            return
        self.backtracking(left-1, right, res, path+"(")
        if left < right:
            self.backtracking(left, right-1, res, path+")")
