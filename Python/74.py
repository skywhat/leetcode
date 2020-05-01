class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m = len(matrix)
        if m == 0:
            return False
        n = len(matrix[0])
        i, j = 0, m*n-1
        while i<=j:
            mid = (i+j)/2
            if matrix[mid/n][mid%n] == target:
                return True
            if matrix[mid/n][mid%n] < target:
                i = mid+1
            else:
                j=mid-1
        return False
