class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = collections.deque() # put index into deque
        res = []

        for i, n in enumerate(nums):
            if q and i - q[0] >=k:
                q.popleft()
            while q and nums[q[-1]] < n:
                q.pop()
            q.append(i)
            if i>= k-1:
                res.append(nums[q[0]])
        return res
