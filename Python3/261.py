class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        uf = [i for i in range(n)]

        for p, q in edges:
            rootp = self.find(uf, p)
            rootq = self.find(uf, q)
            if rootp == rootq:
                return False
            uf[rootp] = rootq
        return len(edges) == n-1

    # include path compression, flatten the whole path at once after access.
    def find(self, uf, p):
        if uf[p] != p:
            uf[p] = self.find(uf, uf[p])
        return uf[p]
