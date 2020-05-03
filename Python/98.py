# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.isValid(root, None, None)
    
    def isValid(self, root, minR, maxR):
        if root == None:
            return True
        if minR and root.val <= minR.val:
            return False
        if maxR and root.val >= maxR.val:
            return False
        return self.isValid(root.left, minR, root) and self.isValid(root.right, root, maxR)
        

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        s = []
        prev = None
        while s != list() or root:
            while root:
                s.append(root)
                root = root.left
            root = s.pop()
            if prev and prev.val >= root.val:
                return False
            prev = root
            root = root.right
        return True
