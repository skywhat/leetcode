class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.head = Node(-1, -1)
        self.tail = Node(-1, -1)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.capacity = capacity
        self.cache = {}
    
    def _add_node(self, node):
        second = self.head.next
        self.head.next = node
        node.next, node.prev = second, self.head
        second.prev = node

    def _remove_node(self, node):
        prev, next = node.prev, node.next
        prev.next = next
        next.prev = prev
    
    def _move_to_head(self, node):
        self._remove_node(node)
        self._add_node(node)

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        node = self.cache[key]
        self._move_to_head(node)
        return node.value


    def put(self, key: int, value: int) -> None:
        # update the value
        if key in self.cache:
            node = self.cache[key]
            node.value = value
            self._move_to_head(node)
            return
        
        #add new node
        if len(self.cache) == self.capacity:
            lastnode = self.tail.prev
            self._remove_node(lastnode)
            del self.cache[lastnode.key]
        
        node = Node(key, value)
        self._add_node(node)
        self.cache[key] = node
        return


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
