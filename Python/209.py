class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        sum, n = 0, len(nums)
        i,j, minLen = -1, 0, n+1
        while j<n:
            sum += nums[j]
            while sum >= s:
                minLen = min(minLen, j-i)
                i+=1
                sum -=nums[i]
            j+=1
        return minLen if minLen != n+1 else 0
                
