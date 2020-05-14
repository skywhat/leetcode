class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums[0], nums[1])
        if n == 3:
            return max(nums[1], nums[0]+nums[2])
        dp = [0]*n
        dp[0] = nums[0]
        dp[1] = nums[1]
        dp[2] = max(nums[1], nums[0]+nums[2])
        for i in range(3, n):
            dp[i] = max(dp[i-2]+nums[i], max(dp[i-1], dp[i-3] + nums[i]))
        return dp[n-1]
            


class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        dp = [[0]*n for i in range(2)]
        dp[1][0] = nums[0]
        '''
        dp[0][i] don't rob i-th house
        dp[1][i] rob i-th house
        '''
        for i in range(1, n):
            dp[0][i] = max(dp[0][i-1], dp[1][i-1])
            dp[1][i] = max(dp[0][i-1]+nums[i], dp[1][i-1])
        return max(dp[0][n-1], dp[1][n-1])
