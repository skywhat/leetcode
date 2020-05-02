# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prev = cur = head
        while prev:
            while cur and cur.val == prev.val:
                cur = cur.next
            prev.next = cur
            prev = prev.next
        return head
