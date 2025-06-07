class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        if n<4:
            return []
        res = []
        nums = sorted(nums)
        for i in range(n-3):
            if i>0 and nums[i-1] == nums[i]:
                continue
            if nums[i]+nums[i+1] + nums[i+2] + nums[i+3] > target:
                continue
            if nums[i]+nums[n-3]+nums[n-2]+nums[n-1] < target:
                continue
            for j in range(i+1, n-2):
                if j-1>i and nums[j-1] == nums[j]:
                    continue
                if nums[i] + nums[j] + nums[j+1] + nums[j+2] > target:
                    continue
                if nums[i] + nums[j] + nums[n-2] + nums[n-1] < target:
                    continue
                start, end = j+1, n-1
                while start < end:
                    if nums[i]+nums[j] + nums[start] + nums[end] == target:
                        res.append([nums[i], nums[j], nums[start], nums[end]])
                        start +=1
                        end -=1
                    elif nums[i]+nums[j] + nums[start] + nums[end] < target:
                        start +=1
                    else:
                        end -=1
                    while start < end and start-1>j and nums[start] == nums[start-1]:
                        start +=1
                    while start < end and end+1<n and nums[end] == nums[end+1]:
                        end -=1
        return res
                    



