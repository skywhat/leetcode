class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        start = 0
        for n in nums:
            if start < 2 or nums[start-2] < n:
                nums[start] = n
                start +=1
        return start
