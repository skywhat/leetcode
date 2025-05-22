class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        if k >= len(arr):
            return arr
        
        l, r = 0, len(arr) - k
        while l+1 < r:
            mid = (l+r)//2
            if x - arr[mid] <= arr[mid+k] - x:
                r = mid
            else:
                l = mid
        
        pos = l
        if l<r and x-arr[l] > arr[l+k] - x:
            pos = r
        
        return [arr[j] for j in range(pos, pos+k)]

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        arr = sorted(arr, key= lambda a : abs(a-x))
        return sorted(arr[:k])
