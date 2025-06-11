class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        left_bound = min_pos = max_pos = -1
        res = 0
        for i, n in enumerate(nums):
            if n < minK or n > maxK:
                left_bound = i
            if n == minK:
                min_pos = i
            if n == maxK:
                max_pos = i
            res += max(0, min(min_pos, max_pos)-left_bound)
        return res
"""
Algorithm
Initialize three indices minPosition, maxPosition and leftBound as -1 and set answer as 0.

Iterate over nums, for each index i:

If nums[i] is out of the range [minK, maxK], update leftBound = i.
If nums[i] equals minK, update minPosition = i.
If nums[i] equals maxK, update maxPosition = i.
The number of valid subarrays ending at index i equals min(minPosition, maxPosition) - leftBound. If the result is negative, it means there is no valid subarray ending at i. Increment answer by the number of valid subarrays.

Return answer once the iteration stops.
"""
