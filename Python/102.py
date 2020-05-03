# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        d = deque()
        if root:
            d.append(root)
        res = []
        while len(d) != 0:
            n = len(d)
            l = []
            for i in range(n):
                node = d.popleft()
                l.append(node.val)
                if node.left:
                    d.append(node.left)
                if node.right:
                    d.append(node.right)
            res.append(l)
        return res
        
        
