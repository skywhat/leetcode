class Solution:
    def waysToMakeFair(self, nums: List[int]) -> int:
        n = len(nums)
        even_before_sum = [0]*n
        odd_before_sum = [0]*n
        even_before_sum[0] = nums[0]
        for i in range(1, n):
            if i&1:
                odd_before_sum[i] = odd_before_sum[i-1] + nums[i]
                even_before_sum[i] = even_before_sum[i-1]
            else:
                even_before_sum[i] = even_before_sum[i-1] + nums[i]
                odd_before_sum[i] = odd_before_sum[i-1]
        even_after_sum = [0]*n
        odd_after_sum = [0]*n
        if (n-1)&1:
            odd_after_sum[-1] = nums[-1]
        else:
            even_after_sum[-1] = nums[-1]
        for i in range(n-2, -1, -1):
            if i&1:
                odd_after_sum[i] = odd_after_sum[i+1] + nums[i]
                even_after_sum[i] = even_after_sum[i+1]
            else:
                odd_after_sum[i] = odd_after_sum[i+1]
                even_after_sum[i] = even_after_sum[i+1] + nums[i]
        res = 0
        for i in range(n):
            x, y = i-1, i+1
            even = odd = 0
            if x>=0:
                even += even_before_sum[x]
                odd += odd_before_sum[x]
            if y<n:
                even += odd_after_sum[y]
                odd += even_after_sum[y]
            if even == odd:
                res+=1

        return res
    

"""
great explanation: https://medium.com/swlh/ways-to-make-a-fair-array-algorithms-visualizations-a2ae3c9d881e

[2,1,6,4]
even_before_sum = [2,2,8,8]
odd_before_sum = [0,1,1,5]
even_after_sum = [8,6,6,0]
odd_after_sum = [5,5,4,4]

let's say we want to remove the element at index i
even = even_before_sum[i-1] + odd_after_sum[i+1]
odd = odd_before_sum[i-1] + even_after_sum[i+1]
if even == odd, then we can make the array fair by removing the element at index i

example, i = 2
even = even_before_sum[1] + odd_after_sum[3] = 2 + 4 = 6
odd = odd_before_sum[1] + even_after_sum[3] = 1 + 0 = 1

"""
