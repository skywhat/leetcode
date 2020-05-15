# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return max(self.robSubset(root))
        
    def robSubset(self, root):
        if not root:
            return [0, 0]
        res = [0, 0]
        left = self.robSubset(root.left)
        right = self.robSubset(root.right)
        res[0] = max(left[0], left[1]) + max(right[0], right[1])
        res[1] = root.val + left[0] + right[0]
        return res
        
        

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.robMap = {}
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        if root in self.robMap:
            return self.robMap[root]
        left = right = 0
        if root.left:
            left = self.rob(root.left.left) + self.rob(root.left.right)
        if root.right:
            right = self.rob(root.right.left) + self.rob(root.right.right)
        res = max(self.rob(root.left)+self.rob(root.right), root.val + left + right)
        self.robMap[root] = res
        return res
