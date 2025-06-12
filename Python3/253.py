class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        h = []
        intervals = sorted(intervals, key=lambda x:(x[0], x[1]))

        for start, end in intervals:
            if not h:
                heapq.heappush(h, end)
            else:
                if h[0] <= start:
                    heapq.heappop(h)
                heapq.heappush(h, end)
        return len(h)

class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        count = collections.defaultdict(int)
        for i, j in intervals:
            count[i] +=1
            count[j] -=1
        
        res = 0
        room = 0
        for t in sorted(count.keys()):
            room += count[t]
            res = max(res, room)
        return res
