class Solution(object):
    def longestMountain(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n = len(A)
        ups = [0]*n
        downs = [0]*n
        for i in range(n-2, -1, -1):
            if A[i] > A[i+1]:
                downs[i] = downs[i+1]+1
        
        res = 0
        for i in range(1, n):
            if A[i] > A[i-1]:
                ups[i] = ups[i-1]+1
            if ups[i] and downs[i]:
                res = max(res, ups[i]+downs[i]+1)
                
        return res


# one pass with O(1) space.
class Solution(object):
    def longestMountain(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        res = ups = downs = 0
        n = len(A)
        if n<3:
            return 0
        for i in range(1, n):
            if (downs and A[i-1] < A[i]) or (A[i-1] == A[i]):
                ups = downs = 0
            if A[i-1] < A[i]:
                ups +=1
            elif A[i-1] > A[i]:
                downs +=1
            if ups and downs:
                res = max(res, ups + downs +1)
        
        return res
