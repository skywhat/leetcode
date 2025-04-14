class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        start = 0
        for i in range(1, len(nums)):
            # compare the value with coming new values,
            # if it is different, assign the new value to the next position.
            if nums[start] != nums[i]:
                start +=1
                nums[start] = nums[i]
        return start + 1
