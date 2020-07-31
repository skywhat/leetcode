class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        n = len(nums)
        dp = [0]*n
        dp[0] = nums[0]
        pos = 1
        for i in range(1, n):
            if nums[i] < dp[0]:
                dp[0] = nums[i]
            elif nums[i] > dp[pos-1]:
                dp[pos] = nums[i]
                pos+=1
            else:
                z = self.findPos(nums, 0, pos-1, nums[i], dp)
                dp[z] = nums[i]
        return pos
    
    def findPos(self, nums, l, r, n, dp):
        while l+1 < r:
            mid = (l+r)/2
            if dp[mid] == n:
                return mid
            elif dp[mid] < n:
                l = mid
            else:
                r = mid
        if dp[l] >= n:
            return l
        return r
        
                

class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        n = len(nums)
        dp = [1]*n
        maxLen = 1
        for i in range(n):
            for j in range(i):
                if nums[j] < nums[i] and dp[j]+1 > dp[i]:
                    dp[i] = dp[j]+1
                    maxLen = max(maxLen, dp[i])
        return maxLen
