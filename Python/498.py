class Solution(object):
    def findDiagonalOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        m = len(matrix)
        if not m:
            return []
        n = len(matrix[0])
        res = []
        for i in range(m+n-1):
            s = []
            if i<=n-1:
                x = 0
            else:
                x = i-(n-1)
            if i>n-1:
                y = n-1
            else:
                y = i
            
            while x<m and y>=0:
                s.append(matrix[x][y])
                x+=1
                y-=1

            if i%2 == 1:
                res += s
            else:
                res += s[::-1]
        return res

class Solution(object):
    def findDiagonalOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        m = len(matrix)
        if not m:
            return []
        n = len(matrix[0])
        d = defaultdict(list)
        for i in range(m):
            for j in range(n):
                d[i+j].append(matrix[i][j])
        res = []
        for k in range(m+n-1):
            if k%2 == 1:
                res += d[k][:]
            else:
                res += d[k][::-1]

        return res
