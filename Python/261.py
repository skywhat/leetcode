#DFS using stack
class Solution(object):
    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
        adjList = [[] for _ in range(n)]

        stack = [0]
        seen = set([0])
        parent = {}
        for e in edges:
            adjList[e[0]].append(e[1])
            adjList[e[1]].append(e[0])

        while stack:
            node = stack.pop()
            for ne in adjList[node]:
                if node in parent and ne == parent[node]:
                    continue
                if ne in seen:
                    return False
                stack.append(ne)
                seen.add(ne)
                parent[ne] = node
        return len(seen) == n


#BFS using queue
class Solution(object):
    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
        adjList = [[] for _ in range(n)]

        q = collections.deque([0])
        seen = set([0])
        parent = {}
        for e in edges:
            adjList[e[0]].append(e[1])
            adjList[e[1]].append(e[0])

        while q:
            node = q.popleft()
            for ne in adjList[node]:
                if node in parent and parent[node] == ne:
                    continue
                if ne in seen:
                    return False
                q.append(ne)
                seen.add(ne)
                parent[ne] = node
        return len(seen) == n


#union find
class Solution(object):
    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
        uf = [-1]*n
        for e in edges:
            r1 = self.find(uf, e[0])
            r2 = self.find(uf, e[1])
            if r1 == r2:
                return False
            uf[r1] = r2
        return len(edges) == n-1

    def find(self, uf, p):
        if uf[p] == -1:
            return p
        return self.find(uf, uf[p])

#union find with path compression.
class Solution(object):
    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
        uf = [i for i in range(n)]
        for e in edges:
            r1 = self.find(uf, e[0])
            r2 = self.find(uf, e[1])
            if r1 == r2:
                return False
            uf[r1] = r2
        return len(edges) == n-1

    def find(self, uf, p):
        while uf[p] != p:
            uf[p] = uf[uf[p]]
            p = uf[p]
        return p
