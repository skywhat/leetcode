"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next
"""

class Solution:
    def insert(self, head: 'Optional[Node]', insertVal: int) -> 'Node':
        node = Node(insertVal)
        if not head:
            node.next = node
            return node
        prev, cur = head, head.next
        while prev.next != head:
            # case 1, 3=>4=>1=>2=>
            if prev.val <= node.val and node.val <= cur.val:
                break
            # case 2, 3=>4=>0=>1=> or 3=>4=>5=>1
            if prev.val > cur.val and (node.val <= cur.val or node.val >= prev.val):
                break
            prev, cur = prev.next, cur.next
        prev.next = node
        node.next = cur

        return head
