# hash with linked list to resolve the collision.
class Node(object):
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

class MyHashMap(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.size = 997
        self.hash = [None]*self.size
        

    def put(self, key, value):
        """
        value will always be non-negative.
        :type key: int
        :type value: int
        :rtype: None
        """
        pos = key % self.size
        if self.hash[pos] == None:
            self.hash[pos] = Node(key, value)
            return
        head = prev = self.hash[pos]
        while head:
            if head.key == key:
                head.value = value
                return
            prev = head
            head = head.next
        prev.next = Node(key, value)
        

    def get(self, key):
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        :type key: int
        :rtype: int
        """
        pos = key %self.size
        if self.hash[pos] == None:
            return -1
        head = self.hash[pos]
        while head:
            if head.key == key:
                return head.value
            head = head.next
        return -1
        

    def remove(self, key):
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        :type key: int
        :rtype: None
        """
        pos = key % self.size
        if self.hash[pos] == None:
            return
        head = self.hash[pos]
        if head.key == key:
            self.hash[pos] = head.next
            return
        prev, head = head, head.next
        while head:
            if head.key == key:
                prev.next = head.next
                return
            prev, head = head, head.next


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
