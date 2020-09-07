class Solution(object):
    def multiply(self, A, B):
        """
        :type A: List[List[int]]
        :type B: List[List[int]]
        :rtype: List[List[int]]
        """
        m, mn, n = len(A), len(B), len(B[0])
        res = [[0]*n for _ in range(m)]
        for i in range(m):
            for j in range(mn):
                if A[i][j] == 0:
                    continue
                for k in range(n):
                    if B[j][k] == 0:
                        continue
                    res[i][k] += A[i][j]*B[j][k]
        return res
