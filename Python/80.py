class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        start = i = 0
        while i<len(nums):
            nums[start] = nums[i]
            start +=1
            i+=1
            if i<len(nums):
                if nums[i] == nums[i-1]:
                    nums[start] = nums[i]
                    start +=1
                    i+=1
            while i<len(nums) and nums[i] == nums[i-1]:
                i+=1
        return start

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = start = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                nums[start] = nums[i]
                start +=1
                count = 1
            elif count < 2:
                nums[start] = nums[i]
                start +=1
                count+=1
        return start
