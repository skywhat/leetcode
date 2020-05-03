# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root == None:
            return True
        return self.isMirror(root.left, root.right)

    def isMirror(self, p, q):
        if p == None and q == None:
            return True
        if p == None:
            return False
        if q == None:
            return False
        return p.val == q.val and self.isMirror(p.left, q.right) and self.isMirror(p.right, q.left)
