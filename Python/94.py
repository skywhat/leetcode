class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res = []
        self.dfs(root, res)
        return res
    
    def dfs(self, root, res):
        if root:
            self.dfs(root.left, res)
            res.append(root.val)
            self.dfs(root.right, res)



class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res = []
        stack = []

        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            res.append(root.val)
            root = root.right
        return res

#O(1) space
#without modifying tree
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res = []
        cur = root
        while cur:
            if cur.left:
                prev = cur.left
                while prev.right and prev.right != cur:
                    prev = prev.right
                if prev.right == None:
                    prev.right = cur
                    cur = cur.left
                else:
                    prev.right = None
                    res.append(cur.val)
                    cur = cur.right
            else:
                res.append(cur.val)
                cur = cur.right
        return res

#O(1) space
#modifying tree
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res = []
        cur = root
        while cur:
            if cur.left:
                prev = cur.left
                while prev.right and prev != cur:
                    prev = prev.right
                if prev.right == None:
                    prev.right = cur
                    cur = cur.left
                    prev.right.left = None
                else:
                    cur = cur.right
            else:
                res.append(cur.val)
                cur = cur.right
        return res
