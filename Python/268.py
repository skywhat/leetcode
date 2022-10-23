class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        n = len(nums)
        for i in range(n):
            res ^= i^nums[i]
        return res^n
      
class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        s = (1+n)*n/2
        for num in nums:
            s -=num
        return s
