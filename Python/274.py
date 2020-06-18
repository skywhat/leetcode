class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        if not citations:
            return 0
        n = len(citations)
        bucket = [0]*(n+1)
        for c in citations:
            if c >= n:
                bucket[n]+=1
            else:
                bucket[c] +=1
        count = 0
        for i in range(n, -1, -1):
            count += bucket[i]
            if count >= i:
                return i
        return 0
