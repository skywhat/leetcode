#Deque
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        q = collections.deque()
        def clean_deque(i):
            if q and i-q[0] >= k:
                q.popleft()
            while q and nums[q[-1]] < nums[i]:
                q.pop()
        res = []
        for i in range(len(nums)):
            clean_deque(i)
            q.append(i)
            if i>=k-1:
                res.append(nums[q[0]])
        return res


