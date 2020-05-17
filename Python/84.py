class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        s = []
        i = maxArea = 0
        heights.append(0)
        while i<len(heights):
            if not s or heights[s[-1]] <= heights[i]:
                s.append(i)
                i+=1
            else:
                h = heights[s[-1]]
                s.pop()
                left = s[-1] if s else -1
                maxArea = max(maxArea, (i-left-1)*h)
        return maxArea
