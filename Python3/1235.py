class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        jobs = sorted(zip(startTime, endTime, profit))
        h = []
        total = 0
        for s, e, p in jobs:
            while h and h[0][0] <= s:
                _, profit_until_now = heapq.heappop(h)
                total = max(total, profit_until_now)
            heapq.heappush(h, (e, total + p))
        
        while h:
            _, profit_until_now = heapq.heappop(h)
            total = max(total, profit_until_now)
        return total
            
