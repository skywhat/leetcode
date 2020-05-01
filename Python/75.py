class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        color = [0]*3
        for n in nums:
            color[n] +=1
        i = j = 0
        while i<=2:
            while color[i] != 0:
                nums[j] = i
                color[i] -= 1
                j+=1
            i+=1


