# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        prevHead = l3 = ListNode(-1)
        carry = 0
        while l1 or l2 or carry:
            val = 0
            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val +=l2.val
                l2 = l2.next
            if carry:
                val += carry
            l3.next = ListNode(val%10)
            carry = val/10
            l3 = l3.next
        return prevHead.next
        
