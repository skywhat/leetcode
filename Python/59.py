class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        left, right, top, bottom = 0, n-1, 0, n-1
        m = [[0]*n for i in range(n)]
        val = 1
        while left<=right and top <= bottom:
            for i in range(left, right+1):
                m[top][i] = val
                val +=1
            top +=1
            for i in range(top, bottom+1):
                m[i][right] = val
                val +=1
            right -=1
            for i in range(right, left-1, -1):
                m[bottom][i] = val
                val +=1
            bottom -=1
            for i in range(bottom, top-1, -1):
                m[i][left] = val
                val +=1
            left +=1
        return m
