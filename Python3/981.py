class TimeMap:

    def __init__(self):
        self.hashmap = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.hashmap[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.hashmap:
            return ""
        if timestamp < self.hashmap[key][0][0]:
            return ""
        
        i, j = 0, len(self.hashmap[key]) - 1
        while i+1 < j:
            mid = (i+j)//2
            if self.hashmap[key][mid][0] <= timestamp and self.hashmap[key][mid+1][0] > timestamp:
                return self.hashmap[key][mid][1]
            elif self.hashmap[key][mid][0] > timestamp:
                j = mid -1
            else:
                i = mid+1
        # i== j or i+1 == j
        if self.hashmap[key][j][0] <= timestamp:
            return self.hashmap[key][j][1]
        return self.hashmap[key][i][1]



# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
