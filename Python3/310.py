class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        graph = defaultdict(set)
        for x, y in edges:
            graph[x].add(y)
            graph[y].add(x)
        left_n = n
        q = deque()
        for i in range(n):
            if len(graph[i]) == 1:
                q.append(i)
        
        while left_n > 2:
            size = len(q)
            for _ in range(size):
                node = q.popleft()
                next = graph[node].pop()
                graph[next].discard(node)
                if len(graph[next]) == 1:
                    q.append(next)
            left_n -= size
        return list(q)
