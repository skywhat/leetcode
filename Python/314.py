# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def verticalOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        qtree = collections.deque()
        res = collections.defaultdict(list)
        if root:
            qtree.append((root, 0))
            res[0] = [root.val]
        while qtree:
            node, pos = qtree.popleft()
            if node.left:
                qtree.append((node.left, pos-1))
                res[pos-1].append(node.left.val)
            if node.right:
                qtree.append((node.right, pos+1))
                res[pos+1].append(node.right.val)
        keys = sorted(res.keys())
        return [res[k] for k in keys]
