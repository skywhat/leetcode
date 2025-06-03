class Allocator:

    def __init__(self, n: int):
        self.blocks = defaultdict(list)
        self.m = [-1]*n
        self.n = n

    def allocate(self, size: int, mID: int) -> int:
        cnt = 0
        for i in range(self.n):
            if self.m[i] == -1:
                cnt +=1
            else:
                cnt = 0
            if cnt == size:
                self.m[i-cnt+1:i+1] = [mID]*size
                self.blocks[mID].extend([j for j in range(i-cnt+1, i+1)])
                return i-cnt+1
        return -1

    def freeMemory(self, mID: int) -> int:
        to_be_empty_list = self.blocks[mID]
        for i in to_be_empty_list:
            self.m[i] = -1
        self.blocks[mID] = []
        return len(to_be_empty_list)


# Your Allocator object will be instantiated and called as such:
# obj = Allocator(n)
# param_1 = obj.allocate(size,mID)
# param_2 = obj.freeMemory(mID)
