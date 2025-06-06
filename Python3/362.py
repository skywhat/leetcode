#Solution 1, use deque
class HitCounter:

    def __init__(self):
        self.q = deque()

    def hit(self, timestamp: int) -> None:
        self.q.append(timestamp)

    def getHits(self, timestamp: int) -> int:
        while self.q and timestamp - self.q[0] >= 300:
            self.q.popleft()
        return len(self.q)


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)


#Solution 2, O(1) hit, O(s) getHits, s == 300
class HitCounter:

    def __init__(self):
        self.times = [0]*300
        self.hits = [0]*300
        

    def hit(self, timestamp: int) -> None:
        idx = timestamp %300
        if self.times[idx] != timestamp:
            self.times[idx] = timestamp
            self.hits[idx] = 1
        else:
            self.hits[idx] +=1

    def getHits(self, timestamp: int) -> int:
        return sum([hit for i, hit in enumerate(self.hits) if self.times[i] + 300 > timestamp])


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)


