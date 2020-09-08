class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        if n == 1:
            return [0]
        adj = [set() for _ in range(n)]
        for e in edges:
            adj[e[0]].add(e[1])
            adj[e[1]].add(e[0])
        
        leaves = [i for i in range(n) if len(adj[i]) == 1]
        
        while n > 2:
            n -= len(leaves)
            t = []
            for l in leaves:
                next = adj[l].pop()
                adj[next].discard(l)
                if len(adj[next]) == 1:
                    t.append(next)
            leaves = t
        return leaves
