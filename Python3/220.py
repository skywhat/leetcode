class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], indexDiff: int, valueDiff: int) -> bool:
        buckets = {}
        bucket_size = valueDiff + 1
        # example bucket_size = 3
        # -1: -3, -2, -1
        # 0: 0, 1, 2
        # 1: 3, 4, 5
        for i in range(len(nums)):
            idx = nums[i] // bucket_size
            if idx in buckets:
                return True
            buckets[idx] = nums[i]
            if idx-1 in buckets and buckets[idx] - buckets[idx-1] <= valueDiff:
                return True
            if idx+1 in buckets and buckets[idx+1] - buckets[idx] <= valueDiff:
                return True
            
            if len(buckets) > indexDiff:
                to_be_deleted_idx = nums[i-indexDiff] // bucket_size
                del buckets[to_be_deleted_idx]
        return False

"""
[1,5,2,4,3,9,1,5,9], k = 2, t = 3

1 // (3+1) = 0
5 // (3+1) = 1
2 // (3+1) = 0
4 // (3+1) = 1
3 // (3+1) = 0
9 // (3+1) = 2

Here, Bucket[0] will contain numbers 0,1,2,3.
Bucket[1] will contain numbers 4,5,6,7.
Bucket[2] will contain numbers 8,9,10,11.

On observing carefully, we can see that the absolute difference
between any two numbers in any bucket is at most t, which is what we want.

Also, there can be a case where the neighbouring bucket has some number
whose absolute difference with a number in the current bucket is at most t.
For instance, 2 lies in Bucket[0] and 4 lies in Bucket[1] and 4 - 2 = 2 < 3 (=t).
This can only happen in neighbouring buckets. Therefore, we need to check for this too.
"""
