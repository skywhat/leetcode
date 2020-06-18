class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        i, j = 0, n-1
        while i<=j:
            mid = i+(j-i)/2
            if citations[mid] >= n-mid:
                j = mid-1
            else:
                i = mid+1
        return n-i
