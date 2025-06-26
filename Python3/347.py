class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        cnt = collections.Counter(nums)
        h = []
        for key, freq in cnt.items():
            heapq.heappush(h, (freq, key))
            if len(h) > k:
                heapq.heappop(h)
        
        return [x[1] for x in h]
