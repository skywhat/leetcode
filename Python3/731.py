class MyCalendarTwo:

    def __init__(self):
        self.intervals = []
        self.overlap = []

    def book(self, startTime: int, endTime: int) -> bool:
        for i, j in self.overlap:
            if startTime < j and endTime > i:
                return False
        for i, j in self.intervals:
            if startTime < j and endTime > i:
                self.overlap.append([max(i, startTime), min(j, endTime)])
        
        self.intervals.append([startTime, endTime])
        return True
        


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(startTime,endTime)
