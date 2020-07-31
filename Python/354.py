class Solution(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        envs = sorted(envelopes, key= lambda x:(x[0], -x[1]))
        nums = [e[1] for e in envs]
        n = len(nums)
        if not n:
            return 0
        dp = [0]*n
        dp[0] = nums[0]
        pos = 1
        for i in range(1, n):
            if nums[i] < dp[0]:
                dp[0] = nums[i]
            elif nums[i] > dp[pos-1]:
                dp[pos] = nums[i]
                pos +=1
            else:
                z = self.find(dp, pos, nums[i])
                dp[z] = nums[i]
        return pos
    
    def find(self, dp, pos, n):
        i, j = 0, pos-1
        while i+1<j:
            mid = (i+j)/2
            if dp[mid] == n:
                return mid
            elif dp[mid] < n:
                i = mid
            else:
                j = mid
        if dp[i] >= n:
            return i
        return j
