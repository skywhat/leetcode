class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n<=2:
            return 0
        l = r = 0
        i, j = 1, n-2
        res = 0
        while i<=j:
            l = max(l, height[i-1])
            r = max(r, height[j+1])

            if l<r:
                res += max(0, l-height[i])
                i+=1
            else:
                res += max(0, r-height[j])
                j-=1
        return res
