class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i, j = 0, len(height)-1
        water = 0
        while i<j:
            water = max(water, (j-i)*min(height[i], height[j]))
            if height[i] < height[j]:
                i +=1
            else:
                j -=1
        return water
                
            
            
        
        

'''
1,8,6,2,5,4,8,3,7
0 1 2 3 4 5 6 7 8
'''
