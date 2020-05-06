# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        if root.left == None or root.right == None:
            return max(self.minDepth(root.left), self.minDepth(root.right))+1
        else:
            return min(self.minDepth(root.left), self.minDepth(root.right))+1
