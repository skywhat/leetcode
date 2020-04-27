class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if nums == list():
            return -1
        if len(nums) == 1:
            return 0 if nums[0] == target else -1
        if nums[0] < nums[-1]:
            return self.binarySearch(nums, 0, len(nums)-1, target)
        
        pivot = self.findPivot(nums)
        if nums[0] > target:
            return self.binarySearch(nums, pivot+1, len(nums)-1, target)
        return self.binarySearch(nums, 0, pivot, target)
    
    def findPivot(self, nums):
        left, right = 0, len(nums)-1
        while left + 1 < right:
            mid = (left+right)/2
            if nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1]:
                return mid
            if nums[0] > nums[mid]:
                right = mid-1
            else:
                left = mid+1
        if nums[left] < nums[right]:
            return right
        return left
        
    
    def binarySearch(self, nums, left, right, target):
        while left + 1 < right:
            mid = (left+right)/2
            if nums[mid] == target:
                return mid
            if nums[mid] < target:
                left = mid+1
            else:
                right = mid-1
        if nums[left] == target:
            return left
        if nums[right] == target:
            return right
        return -1
