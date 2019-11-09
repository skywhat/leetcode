class Solution(object):
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        if len(A) == 0:
            return [[]]
        rowlen = len(A)
        collen = len(A[0])
        res = [[0]*rowlen for i in range(collen)]
        for i in range(rowlen):
            for j in range(collen):
                res[j][i] = A[i][j]
        return res
                
