class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        m = defaultdict(int)
        m[0] = 1
        sum = 0
        cnt = 0
        for n in nums:
            sum +=n
            cnt += m[sum-k]
            m[sum] +=1
        return cnt
