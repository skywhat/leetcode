# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head == None:
            return head
        prevHead = prev = ListNode(-1)
        next = head
        i=0
        while True:
            while i < k and next != None:
                next = next.next
                i+=1
            if i == k:
                prev.next = self.reverseList(head, next)
                prev = head
                head = next
                i = 0
            else:
                prev.next = head
                break
        return prevHead.next  
        
    def reverseList(self, head, end):
        prev = None
        while head != end:
            next = head.next
            head.next = prev
            prev = head
            head = next
        return prev
