class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = -float('inf')
        left = right = 1
        n = len(nums)
        for i in range(n):
            left *= nums[i]
            right *= nums[n-i-1]
            res = max(res, left, right)
            if nums[i] == 0:
                left = 1
            if nums[n-i-1] == 0:
                right = 1
        return res
