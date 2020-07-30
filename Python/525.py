class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sum = 0
        m = {0:-1}
        maxLen = 0
        for i, n in enumerate(nums):
            if n == 0:
                sum -=1
            else:
                sum +=1
            if sum not in m:
                m[sum] = i
            else:
                maxLen = max(maxLen, i-m[sum])
        return maxLen
