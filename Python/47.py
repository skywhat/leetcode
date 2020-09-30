class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        nums = sorted(nums)
        def dfs(res, nums, pos):
            if pos >= len(nums):
                res.append(nums[:])
                return
            uniques = set()
            for i in range(pos, len(nums)):
                if nums[i] in uniques:
                    continue
                uniques.add(nums[i])
                nums[i], nums[pos] = nums[pos], nums[i]
                dfs(res, nums, pos+1)
                nums[i], nums[pos] = nums[pos], nums[i]
                
        dfs(res, nums, 0)
        return res

class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        nums = sorted(nums)
        def dfs(res, nums, path):
            if not nums:
                res.append(path)
            else:
                for i in range(len(nums)):
                    if i>0 and nums[i] == nums[i-1]:
                        continue
                    dfs(res, nums[:i]+nums[i+1:], path + [nums[i]])
                
        dfs(res, nums, [])
        return res

# https://www.educative.io/page/11000001/90001
class Solution(object):
    def permuteUnique(self, nums):
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

                cnts[i] -=1
                res[pos] = vals[i]
                dfs(vals, cnts, res, pos+1)
                cnts[i] +=1

        dfs(vals, cnts, res, 0)
        return ans
