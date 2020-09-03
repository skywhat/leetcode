#recursive
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return "N#"
        res = str(root.val) + "#"
        res += self.serialize(root.left)
        res += self.serialize(root.right)
        return res

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        q = collections.deque(data.split("#"))
        return self.buildTree(q)

    def buildTree(self, q):
        node = q.popleft()
        if node == "N":
            return None
        root = TreeNode(int(node))
        root.left = self.buildTree(q)
        root.right = self.buildTree(q)
        return root


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))

#iterative
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return ""
        q = deque([root])
        res = []
        while q:
            node = q.popleft()
            if node:
                q.append(node.left)
                q.append(node.right)
                res.append(str(node.val))
            else:
                res.append("N")

        return "#".join(res)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return None
        vals = data.split("#")
        q = deque()
        q.append(TreeNode(int(vals[0])))
        ind = 1
        root = q[0]
        while q:
            node = q.popleft()
            if vals[ind] != "N":
                node.left = TreeNode(int(vals[ind]))
                q.append(node.left)
            ind +=1
            if vals[ind] != "N":
                node.right = TreeNode(int(vals[ind]))
                q.append(node.right)
            ind +=1
        return root




# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
