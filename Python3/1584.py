class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        graph = defaultdict(list)
        n = len(points)
        for i in range(n):
            for j in range(i):
                x1, y1, x2, y2 = points[i][0], points[i][1], points[j][0], points[j][1]
                dist = self.cost(x1, y1, x2, y2)
                graph[i].append((dist, j))
                graph[j].append((dist, i))
        
        h = graph[0] # distance, index
        heapq.heapify(h)
        total_cost = 0
        visited = [False]*n
        visited[0] = True
        while h:
            dist, idx = heapq.heappop(h)
            if not visited[idx]:
                total_cost += dist
                visited[idx] = True
                for new_dist, next_idx in graph[idx]:
                    heapq.heappush(h, (new_dist, next_idx))

        return total_cost
        
    def cost(self, x1, y1, x2, y2):
        return abs(x1-x2) + abs(y1-y2)
