class Solution(object):
    def maxSubArrayLen(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        m = {0:-1}
        maxLen = 0
        sum = 0
        for i, n in enumerate(nums):
            sum += n
            if sum-k in m:
                maxLen = max(maxLen, i - m[sum-k])
            if sum not in m:
                m[sum] = i
        return maxLen
