# Time Limit Exceeded
class Solution(object):
    def minKBitFlips(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        res = 0
        n = len(A)
        for i in range(n):
            if A[i] == 0:
                if i+K > n:
                    return -1
                for j in range(K):
                    A[i+j] ^=1
                res +=1
        return res
        
