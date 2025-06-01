class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        heights.append(0)
        i = 0
        max_area = 0
        while i<len(heights):
            if not stack or heights[stack[-1]] <= heights[i]:
                stack.append(i)
                i+=1
            else:
                h = heights[stack.pop()]
                left = stack[-1] if stack else -1
                max_area = max(max_area, h*(i-left-1))
        return max_area
#        2, 1, 5, 6, 2, 3, 0
# index. 0, 1, 2, 3, 4, 5, 6
# i = 0 stack = [0]
# i = 1, pop out, stack = [], area = 2*(1-(-1) -1) = 2
# i = 1, stack = [1]
# i = 2, stack = [1, 2]
# i = 3, stack = [1, 2, 3]
# i = 4, pop out, stack = [1, 2], area = 6*(4-2-1) = 6
# i = 4, pop out, stack = [1], area = 5*(4-1-1) = 10
# i = 4, stack = [1, 4]
# i = 5, stack = [1, 4, 5]
# i = 6, pop out, stack = [1, 4], area = 3*(6-4-1) = 3
# i = 6, pop out, stack = [1], area = 2*(6-1-1) = 8
# i = 6, pop out, stack = [], area = 1*(6-(-1)-1) = 6
# i = 6, stack = [6]
# end the whole loop
