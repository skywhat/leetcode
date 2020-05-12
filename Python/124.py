# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        res = [root.val]
        self.maxPathDown(root, res)
        return res[0]
    
    def maxPathDown(self, root, res):
        if not root:
            return 0
        left = max(0, self.maxPathDown(root.left, res))
        right = max(0, self.maxPathDown(root.right, res))
        res[0] = max(res[0], left+right+root.val)
        return max(left, right) + root.val
