# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findDuplicateSubtrees(self, root):
        """
        :type root: TreeNode
        :rtype: List[TreeNode]
        """
        res = []
        count = defaultdict(int)
        
        def postorder(root):
            if not root:
                return "#"
            id = str(root.val) + ","+ postorder(root.left) + "," + postorder(root.right)
            count[id] +=1
            if count[id] == 2:
                res.append(root)
            return id
        postorder(root)
        return res
