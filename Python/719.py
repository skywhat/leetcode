class Solution(object):
    def smallestDistancePair(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums = sorted(nums)
        n = len(nums)
        low = 0
        high = nums[-1] - nums[0]
        
        while low <= high:
            mid = (low+high)/2
            
            count = 0
            j = 1
            for i in range(n):
                while j<n and nums[j]-nums[i] <= mid:
                    j+=1
                # 0 1 2 3   j=3, i=0, +2
                count += j-i-1
            if count >= k:
                high = mid-1
            else:
                low = mid+1
        return low
