# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from collections import deque
class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        d = deque()
        while head:
            d.append(head)
            head = head.next
        prevHead = prev = ListNode(-1)
        while d:
            prev.next = d.popleft()
            prev = prev.next
            if d:
                prev.next = d.pop()
                prev = prev.next
        prev.next = None
        return prevHead.next
