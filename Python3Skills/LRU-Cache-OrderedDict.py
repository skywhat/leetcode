from collections import OrderedDict

class LRUCache:
    def __init__(self, capacity: int):
        self.cache = OrderedDict()
        self.capacity = capacity
    
    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        self.cache.move_to_end(key)
        return self.cache[key]
    
    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.move_to_end(key)
        self.cache[key] = value
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False)
    
    def __str__(self):
        return str(self.cache)


class TTL_LRUCache:
    def __init__(self, capacity: int):
        self.cache = OrderedDict()
        self.capacity = capacity
    
    def get(self, key: int, timestamp: int) -> int:
        if key not in self.cache:
            return -1
        value, expiry_time = self.cache[key]
        if timestamp >= expiry_time:
            del self.cache[key] # remove the expired key from the cache
            return -1
        self.cache.move_to_end(key)
        return value

    def put(self, key: int, value: int, ttl: int, timestamp: int) -> None:
        expiry_time = timestamp + ttl
        if key in self.cache:
            self.cache.move_to_end(key)
        self.cache[key] = (value, expiry_time)
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False)
    
    def __str__(self):
        return str(self.cache)
    

if __name__ == "__main__":
    print("LRUCache")
    cache = LRUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    print(cache)
    print(cache.get(1))
    print(cache)
    cache.put(3, 3)
    print(cache)

    """
    output:
    LRUCache
    OrderedDict([(1, 1), (2, 2)])
    1
    OrderedDict([(2, 2), (1, 1)])
    OrderedDict([(1, 1), (3, 3)])
    """

    print("TTL_LRUCache")
    lru = TTL_LRUCache(capacity=2)

    lru.put("a", 100, ttl=5000, timestamp=10000)  # expires at 15000
    lru.put("b", 200, ttl=3000, timestamp=10000)  # expires at 13000

    print(lru.get("a", timestamp=12000))  # 100 (still valid)
    print(lru.get("b", timestamp=14000))  # -1 (expired)
    lru.put("c", 300, ttl=4000, timestamp=14000)
    print(lru.get("a", timestamp=16000))  # -1 (expired)
    print(lru.get("c", timestamp=16000))  # 300
    lru.put("d", 400, ttl=6000, timestamp=16000)
    lru.put("e", 500, ttl=7000, timestamp=16000)
    print(lru.get("c", timestamp=17000))  # -1 (evicted))
    print(lru) # OrderedDict([('d', (400, 22000)), ('e', (500, 23000))])
    lru.get("d", timestamp=17000) # d is recently used, so it is moved to the end of the cache
    print(lru) # OrderedDict([('e', (500, 23000)), ('d', (400, 22000))])


    """
    output:
    TTL_LRUCache
    100
    -1
    -1
    300
    -1
    OrderedDict([('d', (400, 22000)), ('e', (500, 23000))])
    OrderedDict([('e', (500, 23000)), ('d', (400, 22000))])
    
    """




    """
    ✅ Time Complexities
    Operation	Time Complexity	Notes
    move_to_end(key)	O(1)	Internally moves the key to front or end of a doubly linked list
    popitem(last=False)	O(1)	Pops from head (if last=False) or tail (if last=True) directly
    __setitem__ / __getitem__	O(1)	Insertion and lookup are constant time

    🔧 Why O(1)?
    OrderedDict is implemented using a doubly linked list + hash table, so:

    The dict provides O(1) access to nodes.

    The linked list allows O(1) movement and popping from either end.
    
    
    """