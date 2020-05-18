class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if len(height) <3:
            return 0
        l_m, r_m = height[0], height[-1]
        i, j = 1, len(height)-2
        res = 0
        while i<=j:
            l_m = max(l_m, height[i])
            r_m = max(r_m, height[j])
            
            if l_m < r_m:
                res += l_m - height[i]
                i+=1
            else:
                res += r_m - height[j]
                j-=1
        return res
