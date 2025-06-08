class Solution:
    def smallestChair(self, times: List[List[int]], targetFriend: int) -> int:
        avail = [i for i in range(len(times))]
        heapq.heapify(avail)
        sorted_times = sorted([(t[0], t[1], i) for i, t in enumerate(times)])
        seating = []
        for arrival, leave, idx in sorted_times:
            while seating and seating[0][0] <= arrival:
                _, avail_seat = heapq.heappop(seating)
                heapq.heappush(avail, avail_seat)
            assigned_seat = heapq.heappop(avail)
            if idx == targetFriend:
                return assigned_seat
            heapq.heappush(seating, (leave, assigned_seat))
        return 0


