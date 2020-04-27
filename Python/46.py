class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        self.dfs(nums, [], res)
        return res
    
    def dfs(self, nums, path, res):
        if not nums:
            res.append(path)
            return
        for i in range(len(nums)):
            self.dfs(nums[:i]+nums[i+1:], path+[nums[i]], res)




class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        self.permuteNums(nums, 0, res)
        return res

    def permuteNums(self, nums, pos, res):
        if pos >= len(nums):
            res.append(nums[:])
            return

        for i in range(pos, len(nums)):
            nums[i], nums[pos] = nums[pos], nums[i]
            self.permuteNums(nums, pos+1, res)
            nums[i], nums[pos] = nums[pos], nums[i]
