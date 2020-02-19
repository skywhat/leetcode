class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        finding = {}
        for i in range(len(nums)):
            if nums[i] in finding:
                return [finding[nums[i]], i]
            finding[target-nums[i]] = i
        return [-1, -1]
            
