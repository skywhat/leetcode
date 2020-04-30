class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        min_sum = min(0, nums[0])
        res = nums[0]
        sum = nums[0]
        for i in range(1,len(nums)):
            sum += nums[i]
            res = max(res, sum-min_sum)
            min_sum = min(min_sum, sum)
        return res
