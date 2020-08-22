class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return -1
        if nums[0] <= nums[-1]:
            return nums[0]

        l, r = 0, len(nums)-1
        while l+1<r:
            m = (l+r)/2
            if m>0 and m+1 < len(nums) and nums[m-1]> nums[m] and nums[m+1] > nums[m]:
                return nums[m]
            if nums[m] < nums[0]:
                r = m-1
            else:
                l = m+1
        return min(nums[l], nums[r])
