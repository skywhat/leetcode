class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d = {}
        n = len(nums)
        for num in nums:
            d[num] = d.get(num, 0) +1
            if d[num] > n/2:
                return num
        return -1



class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        candidate = nums[0]
        cnt = 0
        for n in nums:
            if cnt == 0:
                candidate = n
            if candidate == n:
                cnt +=1
            else:
                cnt -=1
        return candidate
