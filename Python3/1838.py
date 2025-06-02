class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums = sorted(nums)
        total = 0
        i = 0
        max_freq = 0
        # valid window: total + k >= size*nums[j]
        for j in range(len(nums)):
            total += nums[j]

            while total + k < (j-i+1)*nums[j]:
                total -= nums[i]
                i+=1
            max_freq = max(max_freq, j-i+1)
        return max_freq
