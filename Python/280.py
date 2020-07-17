class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        less = True
        i = 0
        while i+1<len(nums):
            if less:
                if nums[i+1] < nums[i]:
                    nums[i], nums[i+1] = nums[i+1], nums[i]
            else:
                if nums[i+1] > nums[i]:
                    nums[i], nums[i+1] = nums[i+1], nums[i]
            less = not less
            i+=1
