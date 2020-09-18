class Solution(object):
    def diagonalSort(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[List[int]]
        """
        m = len(mat)
        if not m:
            return []
        n = len(mat[0])
        d = defaultdict(list)
        
        for i in range(m):
            for j in range(n):
                d[i-j].append(mat[i][j])
        
        for k in range(m-1, -n, -1):
            d[k] = sorted(d[k], reverse=True)
        for i in range(m):
            for j in range(n):
                mat[i][j] = d[i-j].pop()
        return mat


class Solution(object):
    def diagonalSort(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[List[int]]
        """
        m = len(mat)
        if not m:
            return []
        n = len(mat[0])
        d = defaultdict(list)

        for i in range(m):
            for j in range(n):
                d[i-j].append(mat[i][j])

        for k in range(m-1, -n, -1):
            ls = sorted(d[k])
            if k<0:
                x, y = 0, -k
            else:
                x, y = k,0
            for i in range(len(ls)):
                mat[x][y] = ls[i]
                x+=1
                y = x-k


        return mat
