class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        graph = defaultdict(dict)
        for x, y, price in flights:
            graph[x][y] = price
        
        h = [(0, -1, src)] # (cost, k, city)
        visited = set([(0, src)])
        while h:
            cost, step, city = heapq.heappop(h)
            if city == dst:
                return cost
            if step + 1 <= k:
                for next_city, price in graph[city].items():
                    # if you come to the same city with the same cost, you don't need to visit it again.
                    if (cost + price, next_city) in visited:
                        continue
                    heapq.heappush(h, (cost + price, step+1, next_city))
                    visited.add((cost + price, next_city))
        return -1
