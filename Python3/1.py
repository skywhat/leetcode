class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index = {}
        for i in range(len(nums)):
            if target-nums[i] in index:
                return [index[target-nums[i]], i]
            index[nums[i]] = i
        
        return [-1, -1]
