# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prev = None
        while head != None:
            next = head.next
            head.next = prev
            prev = head
            head = next
        return prev



class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        return self.reverse(head)
        
    def reverse(self, head, prev=None):
        if head == None:
            return prev
        next = head.next
        head.next = prev
        return self.reverse(next, head)
