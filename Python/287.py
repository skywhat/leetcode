// this solution modify the array.
class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(len(nums)):
            while nums[i] != nums[nums[i]-1]:
                temp = nums[i]
                nums[i] = nums[nums[i]-1]
                nums[temp-1] = temp
            if i!= (nums[i]-1) and nums[nums[i]-1] == nums[i]:
                return nums[i]
        return -1

// O(nlogn) binary search
class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        low, high = 1, len(nums)
        while low < high:
            mid = low + (high-low)/2
            cnt = sum(i<=mid for i in nums)
            if cnt > mid:
                high = mid
            else:
                low = mid+1
        return low
