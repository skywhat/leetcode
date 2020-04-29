class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        last = n-1
        for i in range(n-1, -1, -1):
            if i+nums[i] >= last:
                last = i
        return last == 0

class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) <=1:
            return True
        step = 1
        for i in range(len(nums)-2, -1, -1):
            if nums[i] <step:
                step +=1
            else:
                step = 1
        return nums[0] >= step
