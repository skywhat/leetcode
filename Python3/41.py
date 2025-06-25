class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            pos = nums[i]-1 # pos is the index of the number supposed to be at
            while pos >= 0 and pos <n and nums[pos] != nums[i]:
                nums[pos], nums[i] = nums[i], nums[pos]
                pos = nums[i] -1 # update the pos
        
        for i in range(n):
            if nums[i] != i+1:
                return i+1
        return n+1