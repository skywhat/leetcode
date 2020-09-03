"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: Node
        :rtype: str
        """
        if not root:
            return "N#"
        res = str(root.val) + "#"
        if root.children == None:
            res += "0#"
        else:
            res += str(len(root.children)) + "#"
        for ch in root.children:
            res += self.serialize(ch)
        return res
        
		
    
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: Node
        """
        q = deque(data.split("#"))
        return self.build(q)
    
    def build(self, q):
        val = q.popleft()
        if val == "N":
            return None
        root = Node(int(val), [])
        cnt = int(q.popleft())
        for i in range(cnt):
            root.children.append(self.build(q))
        return root
        
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
