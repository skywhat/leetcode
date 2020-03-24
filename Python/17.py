class Solution(object):
    def __init__(self):
        self.mapping = {'0':"", '1':"", '2':"abc", '3':"def", '4':"ghi", '5':"jkl", '6':"mno", '7':"pqrs", '8':"tuv", '9':"wxyz"}
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if digits == "":
            return []
        if len(digits) == 1:
            return list(self.mapping[digits[0]])
        prev = self.letterCombinations(digits[:-1])
        return [s + c for s in prev for c in self.mapping[digits[-1]]]
