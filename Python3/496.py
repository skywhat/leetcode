class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        next_greater = {}
        s = []
        for n in nums2:
            while s and s[-1] < n:
                next_greater[s.pop()] = n
            s.append(n)
        
        res = []
        for n in nums1:
            if n in next_greater:
                res.append(next_greater[n])
            else:
                res.append(-1)
        return res
