class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        res = nums[0]+nums[1]+nums[2]
        diff = abs(res-target)
        for i in range(len(nums)-2):
            j,k = i+1, len(nums)-1
            while j<k:
                sum = nums[i]+nums[j]+nums[k]
                if abs(sum-target)<diff:
                    res = sum
                    diff = abs(sum-target)
                if sum-target > 0:
                    k-=1
                else:
                    j+=1
        return res
            
