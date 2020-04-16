# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        n = len(lists)
        if n == 0:
            return None
        for i in range(n-2, -1, -1):
            lists[i] = self.mergeTwoList(lists[i], lists[i+1])
            lists.pop()
        return lists[0]
    
    def mergeTwoList(self, l1, l2):
        prev = prevHead = ListNode(-1)
        while l1 and l2:
            if l1.val < l2.val:
                prev.next = l1
                l1 = l1.next
            else:
                prev.next = l2
                l2 = l2.next
            prev = prev.next
        if l1:
            prev.next = l1
        if l2:
            prev.next = l2
        return prevHead.next


import heapq

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        curr = prevHead = ListNode(-1)
        ls = [(l.val, l) for l in lists if l]
        heapq.heapify(ls)
        while len(ls) != 0:
            curr.next = heapq.heappop(ls)[1]
            curr = curr.next
            if curr.next:
                heapq.heappush(ls, (curr.next.val, curr.next))
        return prevHead.next
