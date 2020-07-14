# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.res = 0
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def depth(root):
            if not root:
                return 0
            d1 = depth(root.left)
            d2 = depth(root.right)
            self.res = max(self.res, d1+d2)
            return max(d1, d2)+1
        if not root:
            return 0
        depth(root)
        return self.res
