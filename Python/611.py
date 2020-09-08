class Solution(object):
    def triangleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = sorted(nums)
        cnt = 0
        n = len(nums)
        
        for i in range(n-2):
            k = i+2
            if nums[i] == 0:
                continue
            for j in range(i+1, n-1):
                while k<n and nums[i]+nums[j] > nums[k]:
                    k+=1
                cnt += k-j-1
        return cnt
