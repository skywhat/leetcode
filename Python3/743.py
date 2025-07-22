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


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = collections.defaultdict(dict)
        all = set()
        for a, b, t in times:
            graph[a][b] = t
            all.add(a)
            all.add(b)
        if len(all) != n:
            return -1
        
        h = [(0, k)]
        visited = set()
        while h:
            cur_time, node = heapq.heappop(h)
            if node in visited:
                continue
            visited.add(node)
            for next_node, t in graph[node].items():
                heapq.heappush(h, (cur_time+t, next_node))
            if len(visited) == n:
                return cur_time
        return -1
