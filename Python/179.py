class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        if not any(nums):
            return "0"
        l = [str(n) for n in nums]
        return "".join(sorted(l, cmp=lambda x,y : -1 if x+y>y+x else 1))
