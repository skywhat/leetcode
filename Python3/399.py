class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = defaultdict(dict)
        for (x, y), val in zip(equations, values):
            graph[x][y] = val
            graph[y][x] = 1/val
        
        res = []
        def calc(node, target, val, seen):
            if node not in graph:
                return -1.0
            if node == target:
                return val
            
            for next_node in graph[node]:
                if next_node not in seen:
                    seen.add(next_node)
                    res = calc(next_node, target, val*graph[node][next_node], seen)
                    seen.discard(next_node)
                    if res != -1.0:
                        return res
            return -1.0

        for x, y in queries:
            res.append(calc(x, y, 1.0, set([x])))

        return res
