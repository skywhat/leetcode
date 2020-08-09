class Solution(object):
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        ss = sum(nums)
        if ss < S:
            return 0
        if (ss + S)%2 != 0:
            return 0
        target = (ss+S)/2
        dp = [0]*(target+1)
        dp[0] = 1
        for n in nums:
            for i in range(target, n-1, -1):
                dp[i] += dp[i-n]
        return dp[target]

'''
iterate dp backwards, cause dp is reduced
from two dimensions to one dimension.
such as dp[i] = dp[i] + dp[i-n]
right value "dp[i], dp[i-n]" is the dp value last time it computed.
iterate forwards would pollute the old dp value, thus the result will be duplicated.
'''
