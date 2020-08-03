# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def delNodes(self, root, to_delete):
        """
        :type root: TreeNode
        :type to_delete: List[int]
        :rtype: List[TreeNode]
        """
        dset = set(to_delete)
        res = []
        def dfs(root, parent_exist, res):
            if not root:
                return None
            if root.val in dset:
                root.left = dfs(root.left, False, res)
                root.right = dfs(root.right, False, res)
                return None
            else:
                root.left = dfs(root.left, True, res)
                root.right = dfs(root.right, True, res)
                if not parent_exist:
                    res.append(root)
                return root
        
        dfs(root, False, res)
        return res
