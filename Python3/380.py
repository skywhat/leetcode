class RandomizedSet:

    def __init__(self):
        self.hashmap = {}
        self.items = []

    def insert(self, val: int) -> bool:
        if val in self.hashmap:
            return False
        self.items.append(val)
        self.hashmap[val] = len(self.items) -1
        return True

    def remove(self, val: int) -> bool:
        if val not in self.hashmap:
            return False
        idx = self.hashmap[val]
        self.items[idx] = self.items[-1]
        override_val = self.items[idx]
        self.hashmap[override_val] = idx
        self.items.pop()
        del self.hashmap[val]
        return True

    def getRandom(self) -> int:
        idx = int(random.random()*len(self.items))
        return self.items[idx]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
