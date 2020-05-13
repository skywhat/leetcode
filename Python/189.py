class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        if k == 0:
            return
        n = len(nums)
        start = 0
        origin, prev = start, nums[start]
        for i in range(n):
            next = (start+k)%n
            if next == origin:
                nums[next] = prev
                start +=1
                origin, prev = start%n, nums[start%n]
                continue
            tmp = nums[next]
            nums[next] = prev
            prev = tmp
            start = next



class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        k %=len(nums)
        i, j = 0, len(nums)-1
        while i<j:
            nums[i], nums[j] = nums[j], nums[i]
            i, j = i+1, j-1
        i, j = 0, k-1
        while i<j:
            nums[i], nums[j] = nums[j], nums[i]
            i, j = i+1, j-1
        i, j = k, len(nums)-1
        while i<j:
            nums[i], nums[j] = nums[j], nums[i]
            i, j = i+1, j-1
