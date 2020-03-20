class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        res = []
        
        for i in range(len(nums)-2):
            if i>0 and nums[i] == nums[i-1]:
                continue
            if nums[i]+ nums[i+1]+nums[i+2]>0:
                continue
            if nums[i]+nums[-1]+nums[-2]<0:
                i+=1
                continue
            start, end = i+1, len(nums)-1
            while start < end:
                if nums[i] + nums[start] + nums[end] <0:
                    start +=1
                elif nums[i] + nums[start] + nums[end] > 0:
                    end -=1
                else:
                    res.append([nums[i], nums[start], nums[end]])
                    cnt = 1
                    while start + cnt < end and nums[start+cnt] == nums[start]:
                        cnt +=1
                    start += cnt
                    cnt = 1
                    while end - cnt > start and nums[end-cnt] == nums[end]:
                        cnt +=1
                    end -=cnt
        return res
            
