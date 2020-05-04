class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.mstack = []
        

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        if self.stack == list() or x<=self.mstack[-1]:
            self.mstack.append(x)
        self.stack.append(x)
        

    def pop(self):
        """
        :rtype: None
        """
        if self.stack:
            if self.stack[-1] == self.mstack[-1]:
                self.mstack.pop()
            self.stack.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1]
        

    def getMin(self):
        """
        :rtype: int
        """
        return self.mstack[-1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
