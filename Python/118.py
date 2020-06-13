class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows == 0:
            return []
        res = [[1]]
        if numRows == 1:
            return res
        for i in range(1, numRows):
            row = [1]
            for j in range(1, i+1):
                row.append(res[-1][j-1])
                if j < len(res[-1]):
                    row[-1] += res[-1][j]
            res.append(row)
        return res
