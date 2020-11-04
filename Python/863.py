# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def distanceK(self, root, target, K):
        """
        :type root: TreeNode
        :type target: TreeNode
        :type K: int
        :rtype: List[int]
        """
        connect = defaultdict(list)
        
        def buildConnection(parent, child):
            if parent and child:
                connect[parent.val].append(child.val)
                connect[child.val].append(parent.val)
            if child.left != None:
                buildConnection(child, child.left)
            if child.right != None:
                buildConnection(child, child.right)
        
        buildConnection(None, root)
        
        q = deque([target.val])
        seen = set([target.val])
        
        for _ in range(K):
            qlen = len(q)
            for _ in range(qlen):
                node = q.popleft()
                children = connect[node]
                for c in children:
                    if c in seen:
                        continue
                    q.append(c)
                    seen.add(c)
        return list(q)
