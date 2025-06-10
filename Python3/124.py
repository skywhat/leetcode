# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.maxsum = -float("inf")

        def PathSum(root):
            if not root:
                return 0
            leftsum = max(0, PathSum(root.left))
            rightsum = max(0, PathSum(root.right))
            self.maxsum = max(self.maxsum, leftsum + rightsum + root.val)
            return max(leftsum, rightsum) + root.val
        
        PathSum(root)
        return self.maxsum
