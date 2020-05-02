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
        

class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = [[]]
        for i in range(len(nums)):
            n = len(res)
            for j in range(n):
                res.append(res[j]+[nums[i]])
        return res
