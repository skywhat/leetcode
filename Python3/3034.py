class Solution:
    def countMatchingSubarrays(self, nums: List[int], pattern: List[int]) -> int:
        n = len(nums)
        p = len(pattern)
        cnt = 0
        for i in range(n-p):
            if self.match(nums, i, pattern):
                cnt +=1
        return cnt
    
    def match(self, nums, i, pattern):
        for j in range(len(pattern)):
            if pattern[j] == 1:
                if nums[i+j+1] <= nums[i+j]:
                    return False
            elif pattern[j] == 0:
                if nums[i+j+1] != nums[i+j]:
                    return False
            elif pattern[j] == -1:
                if nums[i+j+1] >= nums[i+j]:
                    return False
        return True
