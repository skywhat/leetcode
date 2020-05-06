class Solution(object):
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        res = []
        self.permutate(S, 0, res)
        return res
    
    def permutate(self, S, pos, res):
        if pos >= len(S):
            res.append(S)
            return
        if S[pos].isalpha():
            self.permutate(S[:pos]+S[pos].swapcase()+S[pos+1:], pos+1, res)        
        self.permutate(S, pos+1, res)
