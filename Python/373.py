class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        if not nums1 or not nums2:
            return []
        res = []
        h = []
        heapq.heappush(h, [nums1[0]+nums2[0], 0, 0])
        while h and k>0:
            _, i, j = heapq.heappop(h)
            res.append([nums1[i], nums2[j]])
            #i, j+1
            if j+1<len(nums2):
                heapq.heappush(h, [nums1[i]+nums2[j+1], i, j+1])
            #i+1, j
            if j == 0 and i+1<len(nums1):
                heapq.heappush(h, [nums1[i+1]+nums2[j], i+1, j])
            k-=1
        return res
