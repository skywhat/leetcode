class Solution:
    def maximalPathQuality(self, values: List[int], edges: List[List[int]], maxTime: int) -> int:
        graph = defaultdict(dict)
        for a, b, time in edges:
            graph[a][b] = time
            graph[b][a] = time
        
        self.max_val = 0
        visited = set([0])

        def dfs(node, total_time, visited):
            if total_time > maxTime:
                return
            if node == 0:
                self.max_val = max(self.max_val, sum([values[i] for i in visited]))
            
            for next_node, needed_time in graph[node].items():
                dfs(next_node, total_time + needed_time, visited | set([next_node]))
        
        dfs(0, 0, visited)
        return self.max_val
