class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        maxd = collections.deque()
        mind = collections.deque()
        res = 0
        i = 0
        n = len(nums)

        for j in range(n):
            while maxd and maxd[-1] < nums[j]:
                maxd.pop()
            maxd.append(nums[j])
            while mind and mind[-1] > nums[j]:
                mind.pop()
            mind.append(nums[j])

            while maxd[0] - mind[0] > limit:
                if maxd[0] == nums[i]:
                    maxd.popleft()
                if mind[0] == nums[i]:
                    mind.popleft()
                i+=1
            res = max(res, j-i+1)
        return res
