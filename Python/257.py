# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        res = []
        self.dfs(root, res, "")
        return res
    
    def dfs(self, root, res, path):
        if not root:
            return
        if not root.left and not root.right:
            path += str(root.val)
            res.append(path)
            return
        self.dfs(root.left, res, path + str(root.val) + "->")
        self.dfs(root.right, res, path + str(root.val) + "->")
