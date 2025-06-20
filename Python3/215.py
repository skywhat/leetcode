class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        i, j = 0, len(nums)-1
        while i<=j:
            p = self.partition(nums, i, j)
            if p == len(nums) - k:
                return nums[p]
            elif p < len(nums) -k:
                i = p+1
            else:
                j = p-1
        return -1

    
    def partition(self, nums, i, j):
        pivot = nums[i]
        left, right = i+1, j
        while left <= right:
            if nums[left] > pivot and nums[right] < pivot:
                nums[left], nums[right] = nums[right], nums[left]
            if nums[left] <= pivot:
                left+=1
            if nums[right] >= pivot:
                right-=1
        
        nums[i], nums[right] = nums[right], nums[i]
        return right
