class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        freq = defaultdict(int)

        for n in nums:
            rev = int(str(n)[::-1])
            freq[n-rev] +=1
        res = 0
        for val in freq.values():
            res += val*(val-1)//2
        return res % (10**9+7)
