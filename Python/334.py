class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        if n < 3:
            return False
        dp = [nums[0]]
        for i in range(1, n):
            if nums[i] < dp[0]:
                dp[0] = nums[i]
            elif nums[i] > dp[-1]:
                dp.append(nums[i])
            else:
                z = self.find(dp, nums[i])
                dp[z] = nums[i]
            if len(dp) == 3:
                return True
        return False
    
    def find(self, dp, n):
        i, j = 0, len(dp)-1
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
        

class Solution(object):
    def increasingTriplet(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        c1 = c2 = float("inf")
        for n in nums:
            if n <= c1:
                c1 = n
            elif n<=c2:
                c2 = n
            else:
                return True
        return False
