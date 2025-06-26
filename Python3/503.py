class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        size = len(nums)
        res = [-1]*size
        s = [] # index
        for i in range(size*2):
            idx = i%size
            while s and nums[s[-1]] < nums[idx]:
                res[s.pop()] = nums[idx]
            if i< size:
                s.append(i)
        return res
