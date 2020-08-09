class Node(object):
    def __init__(self):
        self.key = self.value = 0
        self.prev = None
        self.next = None

class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.cap = capacity
        self.cache = {}
        self.size = 0
        self.head, self.tail = Node(), Node()
        self.head.next = self.tail
        self.tail.prev = self.head
        
    def _add_node(self, node):
        next = self.head.next
        node.next = next
        next.prev = node
        node.prev = self.head
        self.head.next = node
    
    def _remove_node(self, node):
        next = node.next
        prev = node.prev
        prev.next = next
        next.prev = prev
    
    def _move_to_head(self, node):
        self._remove_node(node)
        self._add_node(node)
    
    def _pop_tail(self):
        node = self.tail.prev
        self._remove_node(node)
        return node

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.cache:
            return -1
        self._move_to_head(self.cache[key])
        return self.cache[key].value
        

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        if key in self.cache:
            self.cache[key].value = value
            self._move_to_head(self.cache[key])
            return
        if self.size == self.cap:
            tailnode = self._pop_tail()
            del self.cache[tailnode.key]
            self.size -=1
        node = Node()
        node.key, node.value = key, value
        self._add_node(node)
        self.cache[key] = node
        self.size +=1
            
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
