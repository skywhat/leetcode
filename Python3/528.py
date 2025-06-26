class Solution:

    def __init__(self, w: List[int]):
        self.presum = []
        total = 0
        for n in w:
            total += n
            self.presum.append(total)

    def pickIndex(self) -> int:
        target = int(random.random()*self.presum[-1])
        i, j = 0, len(self.presum) - 1
        while i+1 < j:
            mid = (i+j)//2
            if self.presum[mid] > target:
                j = mid
            else:
                i = mid
        if self.presum[i] > target:
            return i
        return j


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
