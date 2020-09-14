class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        n = len(arr)
        arr = sorted(arr)
        if k>=n:
            return arr
        l, r = 0, n-k
        while l+1<r:
            mid = (l+r)/2
            if x-arr[mid] > arr[mid+k]-x:
                l = mid
            else:
                r = mid
        pos = l
        if x-arr[l] > arr[l+k]-x:
            pos = r
        return [arr[i] for i in range(pos, pos+k)]

'''
for the general binary search, we can always do it in this way.

while left +1 < right:
	mid = (left+right)/2
	
	if xxx:
		left = mid
	else:
		right = mid

#after get out of the while loop, left+1 = right is always true, then u can check left or right is the valid one.
if left is valid:
	return left
return right
'''
