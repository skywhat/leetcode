# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        qtree = deque()
        q = deque()
        if root:
            qtree.append(root)
            q.append(root.val)
        sum = 0
        while qtree:
            root = qtree.popleft()
            val = q.popleft()
            if root.left == None and root.right == None:
                sum +=val
                continue
            if root.left != None:
                qtree.append(root.left)
                q.append(val*10+root.left.val)
            if root.right != None:
                qtree.append(root.right)
                q.append(val*10+root.right.val)
        return sum

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        sum =[0]
        self.dfs(root, root.val, sum)
        return sum[0]
        
    def dfs(self, root, val, sum):
        if root == None:
            return
        if root.left == None and root.right == None:
            sum[0] += val
            return
        if root.left != None:
            self.dfs(root.left, val*10+root.left.val, sum)
        if root.right != None:
            self.dfs(root.right, val*10+root.right.val, sum)
