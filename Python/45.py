class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n, start, end, maxend = len(nums), 0, 0, 0
        step = 0
        while maxend < n-1:
            # the initial value for next step.
            maxend = end+1
            step +=1
            for i in range(start, end+1):
                if i+nums[i] >= n-1:
                    return step
                maxend = max(maxend, i+nums[i])
            start, end = end+1, maxend
        return step
