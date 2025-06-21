class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        last_idx = {}
        for i, n in enumerate(nums):
            if n in last_idx and i-last_idx[n] <= k:
                return True
            last_idx[n] = i
        return False
