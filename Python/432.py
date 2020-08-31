class Node(object):
    def __init__(self):
        self.keys = set()
        self.prev = self.next = None
        

class AllOne(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = Node()
        self.tail = Node()
        self.head.next = self.tail
        self.tail.prev = self.head
        
        self.keyCount = defaultdict(int)
        self.CountNode = {}
        
        
    def inc(self, key):
        """
        Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        :type key: str
        :rtype: None
        """
        if key in self.keyCount:
            self.changeKey(key, 1)
            return
        
        self.keyCount[key] = 1
        if 1 not in self.CountNode:
            node = Node()
            self._addNodeAfter(node, self.head)
            self.CountNode[1] = node
        self.CountNode[1].keys.add(key)

        
        

    def dec(self, key):
        """
        Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        :type key: str
        :rtype: None
        """
        if key not in self.keyCount:
            return
        if self.keyCount[key] == 1:
            del self.keyCount[key]
            self._removeKeyFromNode(1, key)
            return
        self.changeKey(key, -1)
    
    def _addNodeAfter(self, newNode, cur):
        next = cur.next
        cur.next = newNode
        next.prev = newNode
        newNode.next, newNode.prev = next, cur
    
    def _removeKeyFromNode(self, count, key):
        self.CountNode[count].keys.discard(key)
        if len(self.CountNode[count].keys) == 0:
            self._removeNodeFromList(self.CountNode[count])
            del self.CountNode[count]
        
        
    def _removeNodeFromList(self, node):
        prev, next = node.prev, node.next
        prev.next = next
        next.prev = prev
        
    def changeKey(self, key, delta):
        curVal = self.keyCount[key]
        nextVal = curVal + delta
        self.keyCount[key] = nextVal
        if nextVal not in self.CountNode:
            node = Node()
            self.CountNode[nextVal] = node
            if delta == 1:
                self._addNodeAfter(node, self.CountNode[curVal])
            else:
                self._addNodeAfter(node, self.CountNode[curVal].prev)
        self.CountNode[nextVal].keys.add(key)
        self._removeKeyFromNode(curVal, key)

    def getMaxKey(self):
        """
        Returns one of the keys with maximal value.
        :rtype: str
        """
        # self._printList()
        if self.tail.prev.keys != set():
            return next(iter(self.tail.prev.keys))
        return ""        

    def getMinKey(self):
        """
        Returns one of the keys with Minimal value.
        :rtype: str
        """
        # self._printList()
        if self.head.next.keys != set():
            return next(iter(self.head.next.keys))
        return ""
    
    def _printList(self):
        head = self.head
        while head != self.tail:
            print "keys:", head.keys, "val:", head.val,
            head = head.next
        print
        


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()
