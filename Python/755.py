class Solution(object):
    def pourWater(self, heights, V, K):
        """
        :type heights: List[int]
        :type V: int
        :type K: int
        :rtype: List[int]
        """
        for i in range(V):
            pos = K
            while pos > 0 and heights[pos-1] <= heights[pos]:
                pos -=1
            while pos < K and heights[pos] == heights[pos+1]:
                pos +=1
            if pos == K:
                while pos + 1 < len(heights) and heights[pos+1] <= heights[pos]:
                    pos +=1
                while pos > K and heights[pos] == heights[pos-1]:
                    pos -=1
            heights[pos] +=1
        return heights
