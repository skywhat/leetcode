class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        s = sum(nums)
        if s&1:
            return False
        target = s/2
        dp = [False]*(target+1)
        dp[0] = True
        for n in nums:
            for i in range(target, n-1, -1):
                dp[i] = dp[i] or dp[i-n]
        return dp[target]
