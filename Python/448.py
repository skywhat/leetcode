class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        i = 0
        res = []
        while i<len(nums):
            pos = abs(nums[i])-1
            nums[pos] = -abs(nums[pos])
            i+=1
        for i, n in enumerate(nums):
            if n > 0:
                res.append(i+1)
        return res
