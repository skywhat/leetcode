class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        avail = [i for i in range(n)] # min heap of room
        busy = [] # min heap of (endtime, room number)
        heapq.heapify(avail)
        freq = [0]*n
        # sort the meeting rooms
        meetings = sorted(meetings, key = lambda x:(x[0], x[1]))
        for start, end in meetings:
            # always check if any room can be released.
            while busy and busy[0][0] <= start:
                _, room = heapq.heappop(busy)
                heapq.heappush(avail, room)
            
            # we have available room
            if avail:
                room = heapq.heappop(avail)
                heapq.heappush(busy, (end, room))
                freq[room] +=1
            else:
                # we have no available room, wait until the first room is released.
                current_time, room = heapq.heappop(busy)
                heapq.heappush(busy, (current_time + end-start, room))
                freq[room] +=1
        
        max_freq = max(freq)
        for i in range(n):
            if freq[i] == max_freq:
                return i
        return -1
