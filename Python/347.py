#quick select O(n)
class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        cnt = collections.Counter(nums)
        elems = [ (freq, val) for val, freq in cnt.items()]
        left, right = 0, len(elems)-1
        while left<=right:
            p = self.quickSelect(elems, left, right)
            if p == len(elems)-k:
                return [x[1] for x in elems[p:]]
            elif p > len(elems) - k:
                right = p-1
            else:
                left = p+1
        return []
        
        
    def quickSelect(self, elems, left, right):
        pivot = elems[left][0]
        l, r = left+1, right
        while l<=r:
            if elems[l][0] > pivot and elems[r][0] < pivot:
                elems[l], elems[r] = elems[r], elems[l]
            if elems[l][0] <= pivot:
                l+=1
            if elems[r][0] >= pivot:
                r-=1
        elems[left], elems[r] = elems[r], elems[left]
        return r


class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        cnt = collections.Counter(nums)
        h = []
        res = []
        for val, freq in cnt.items():
            heapq.heappush(h, [-freq, val])
            if len(h) > len(cnt) - k:
                res.append(heapq.heappop(h)[1])
        return res
