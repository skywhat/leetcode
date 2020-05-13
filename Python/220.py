class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        if k < 0 or t < 0:
            return False
        d = {}
        w = t+1
        
        for i in range(len(nums)):
            if i-k>0:
                del d[nums[i-k-1]/w]
            key = nums[i]/w
            if key in d:
                return True
            if key+1 in d and abs(d[key+1]-nums[i])<=t:
                return True
            if key-1 in d and abs(d[key-1]-nums[i]) <= t:
                return True
            d[key] = nums[i]
        return False
