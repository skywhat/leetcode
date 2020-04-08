class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        left, right = 0, len(nums)-1
        while left <= right:
            if nums[left] != val:
                left +=1
                continue
            if nums[right] == val:
                right -=1
                continue
            nums[left], nums[right] = nums[right], nums[left]
            left +=1
            right -=1
        return left
