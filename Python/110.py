# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.depth(root) != -1
    
    def depth(self, root):
        if root == None:
            return 0
        if root.left == None and root.right == None:
            return 1
        d1 = self.depth(root.left)
        if d1 == -1:
            return -1
        d2 = self.depth(root.right)
        if d2 == -1:
            return -1
        if abs(d1-d2) >1:
            return -1
        return max(d1, d2)+1
        
