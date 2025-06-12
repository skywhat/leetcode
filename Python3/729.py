class MyCalendar:
    class Node:
        def __init__(self, start, end):
            self.start = start
            self.end = end
            self.left = self.right = None

    def __init__(self):
        self.root = None

    def book(self, startTime: int, endTime: int) -> bool:
        if not self.root:
            self.root = self.Node(startTime, endTime)
            return True
        return self.insert(self.root, startTime, endTime)

    def insert(self, root, startTime, endTime):
        if endTime <= root.start:
            if not root.left:
                root.left = self.Node(startTime, endTime)
                return True
            return self.insert(root.left, startTime, endTime)
        if startTime >= root.end:
            if not root.right:
                root.right = self.Node(startTime, endTime)
                return True
            return self.insert(root.right, startTime, endTime)
        return False


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(startTime,endTime)
