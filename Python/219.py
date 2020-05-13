class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        d = defaultdict(int)
        for i in range(len(nums)):
            if nums[i] in d:
                if i - d[nums[i]] <=k:
                    return True
            d[nums[i]] = i
        return False
