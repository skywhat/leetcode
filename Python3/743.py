class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = defaultdict(dict)
        for x, y, t in times:
            graph[x][y] = t
        h = [(0, k)]
        res = 0
        visited = set()
        while h:
            t, node = heapq.heappop(h)
            if node in visited:
                continue
            visited.add(node)
            res = max(res, t)
            for next_node in graph[node]:
                heapq.heappush(h, (graph[node][next_node] + t, next_node))
        return res if len(visited) == n else -1
