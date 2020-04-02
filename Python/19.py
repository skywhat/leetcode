# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        prevHead = slow = ListNode(-1)
        prevHead.next = slow.next = head
        for i in range(n):
            head = head.next
        while head != None:
            head = head.next
            slow = slow.next
        slow.next = slow.next.next
        return prevHead.next
