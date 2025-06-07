class MedianFinder:

    def __init__(self):
        """
        two cases
        1. small, large => k, k => k, k+1
            put num into `small`, pop out, move the largest of `small` to `large`
        2. small, large => k, k+1 => k+1, k+1
            put num into `large`, pop out, move the smallest of `large` to `small` 
        """
        self.small = [] # maxheap
        self.large = [] # minheap

    def addNum(self, num: int) -> None:
        if len(self.small) == len(self.large):
            heapq.heappush(self.large, -1*heapq.heappushpop(self.small, -1*num))
        else:
            heapq.heappush(self.small, -1*heapq.heappushpop(self.large, num))

    def findMedian(self) -> float:
        if len(self.small) == len(self.large):
            return (-1*self.small[0] + self.large[0])/2
        return self.large[0]
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()