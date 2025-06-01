class FreqStack:

    def __init__(self):
        self.maxfreq = 0
        self.freq = defaultdict(int)
        self.stack = defaultdict(list)

    def push(self, val: int) -> None:
        self.freq[val] +=1
        self.maxfreq = max(self.maxfreq, self.freq[val])
        self.stack[self.freq[val]].append(val)

    def pop(self) -> int:
        maxfreq = self.maxfreq
        x = self.stack[maxfreq].pop()
        if not self.stack[maxfreq]:
            self.maxfreq -=1
        self.freq[x] -=1
        return x


# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()
