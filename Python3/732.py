class MyCalendarThree:

    def __init__(self):
        self.calendar = collections.defaultdict(int)

    def book(self, startTime: int, endTime: int) -> int:
        self.calendar[startTime] +=1
        self.calendar[endTime] -=1
        res = 0
        booking = 0
        for key in sorted(self.calendar):
            booking += self.calendar[key]
            res = max(res, booking)
        return res


# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(startTime,endTime)
