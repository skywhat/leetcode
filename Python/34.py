class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not nums:
            return [-1, -1]
        start = end = -1
        i, j = 0, len(nums)-1
        while i<j:
            mid = i+(j-i)/2
            if nums[mid] < target:
                i = mid+1
            else:
                j = mid
        start = i
        i, j = 0, len(nums)
        while i<j:
            mid = i+(j-i)/2
            if nums[mid] <= target:
                i = mid+1
            else:
                j = mid
        end = j
        if nums[start] != target:
            return [-1, -1]
        return [start, end-1]
