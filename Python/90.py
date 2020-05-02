class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums = sorted(nums)
        res = []
        self.pick(nums, 0, res, [])
        return res
        
    def pick(self, nums, pos, res, l):
        if pos == len(nums):
            res.append(l)
            return
        cnt = 1
        while pos+cnt < len(nums) and nums[pos+cnt] == nums[pos]:
            cnt +=1
        self.pick(nums, pos+cnt, res, l)
        for i in range(1, cnt+1):
            self.pick(nums,pos+cnt, res, l+[nums[pos]]*i)
