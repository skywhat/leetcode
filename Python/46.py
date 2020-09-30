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

class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        c = Counter(nums)
        vals = sorted(c.keys())
        cnts = [c[v] for v in vals]
        res = [0]*len(nums)
        ans = []
        def dfs(vals, cnts, res, pos):
            if pos >= len(nums):
                ans.append(res[:])
                return

            for i in range(len(vals)):
                if cnts[i] == 0:
                    continue
                n = cnts[i]
                for j in range(n):
                    cnts[i] -=1
                    res[pos] = vals[i]
                    dfs(vals, cnts, res, pos+1)
                    cnts[i] +=1

        dfs(vals, cnts, res, 0)
        return ans
