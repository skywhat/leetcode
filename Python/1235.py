class Solution(object):
    def jobScheduling(self, startTime, endTime, profit):
        """
        :type startTime: List[int]
        :type endTime: List[int]
        :type profit: List[int]
        :rtype: int
        """
        jobs = sorted(zip(startTime, endTime, profit), key = lambda x:x[0])
        
        total = 0
        h = []
        
        for s, e, p in jobs:
            while h and h[0][0] <= s:
                _, profit = heapq.heappop(h)
                total = max(total, profit)
            heapq.heappush(h, (e, total + p))
        
        while h:
            _, profit = heapq.heappop(h)
            total = max(total, profit)
        return total
