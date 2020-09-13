# binary search
class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        n = len(matrix)
        lo, hi = matrix[0][0], matrix[n-1][n-1]
        while lo<=hi:
            mid = (lo+hi)/2
            maxN = lo
            count = 0
            c = n-1
            for r in range(n):
                while c>=0 and matrix[r][c] > mid:
                    c -=1
                if c>=0:
                    count += c+1
                    maxN = max(maxN, matrix[r][c])
            if count == k:
                return maxN
            elif count > k:
                hi = mid-1
            else:
                lo = mid+1
        return lo

# heap
class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        h = []
        n = len(matrix)
        for i in range(n):
            heapq.heappush(h, (matrix[i][0], i, 0))
        while k>0:
            val, row, col = heapq.heappop(h)
            if col+1 < n:
                heapq.heappush(h, (matrix[row][col+1], row, col+1))
            k-=1
        return val
