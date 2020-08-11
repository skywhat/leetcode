# time complexity: O(nlogn)
class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        snums = sorted(nums)
        start = 0
        end = -1
        for i in range(len(nums)):
            if nums[i] != snums[i]:
                start = i
                break
        for i in range(len(nums)-1, -1, -1):
            if nums[i] != snums[i]:
                end = i
                break
        return end - start +1

# time complexity: O(n)
class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        s = []
        l, r = n, 0
        for i, x in enumerate(nums):
            while s and nums[s[-1]] > x:
                l = min(l, s.pop())
            s.append(i)
        s = []
        for i in range(n-1, -1, -1):
            while s and nums[s[-1]] < nums[i]:
                r = max(r, s.pop())
            s.append(i)
        return r-l+1 if r-l>=0 else 0

class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        minN, maxN = nums[-1], nums[0]
        l = 0
        r = -1
        for i in range(len(nums)):
            maxN = max(maxN, nums[i])
            if nums[i] < maxN:
                r = i
                
        for i in range(len(nums)-1, -1, -1):
            minN = min(minN, nums[i])
            if nums[i] > minN:
                l = i
        return r-l+1
