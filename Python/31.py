class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        k = -1
        for i in range(len(nums)-1):
            if nums[i] < nums[i+1]:
                k = i
        if k == -1:
            nums.reverse()
            return
        l = -1
        for i in range(len(nums)-1, -1, -1):
            if nums[i] > nums[k]:
                l = i
                break
        nums[k], nums[l] = nums[l], nums[k]
        i, j = k+1, len(nums)-1
        while i<j:
            nums[i], nums[j] = nums[j], nums[i]
            i+=1
            j-=1
