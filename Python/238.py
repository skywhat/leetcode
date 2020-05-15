class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        res =[1]*n
        product = nums[0]
        for i in range(1, n):
            res[i] = product
            product *=nums[i]
        product = nums[n-1]
        for i in range(n-2, -1, -1):
            res[i] *= product
            product *=nums[i]
        return res
