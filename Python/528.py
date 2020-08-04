class Solution(object):

    def __init__(self, w):
        """
        :type w: List[int]
        """
        self.psum = []
        s = 0
        for n in w:
            s += n
            self.psum.append(s)
        self.total = s
        

    def pickIndex(self):
        """
        :rtype: int
        """
        target = self.total * random.random()
        for i, x in enumerate(self.psum):
            if target < x:
                return i
        return -1
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()


class Solution(object):

    def __init__(self, w):
        """
        :type w: List[int]
        """
        self.psum = []
        s = 0
        for n in w:
            s += n
            self.psum.append(s)
        self.total = s


    def pickIndex(self):
        """
        :rtype: int
        """
        target = self.total * random.random()
        i, j = 0, len(self.psum) -1
        while i+1<j:
            mid = (i+j)/2
            if self.psum[mid] > target:
                j = mid
            else:
                i = mid
        if self.psum[i] >= target:
            return i
        return j



# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
