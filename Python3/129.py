# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        def getSum(root, val):
            if not root:
                return 0
            new_val = val*10 + root.val
            if not root.left and not root.right:
                return new_val
            return getSum(root.left, new_val) + getSum(root.right, new_val)
        return getSum(root, 0) 
