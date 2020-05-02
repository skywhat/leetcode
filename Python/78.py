class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        self.pick(nums, 0, res, [])
        return res
    
    def pick(self, nums, pos, res, l):
        if pos == len(nums):
            res.append(l)
            return
        self.pick(nums, pos+1, res, l)
        self.pick(nums, pos+1, res, l+[nums[pos]])
        
