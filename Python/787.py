class Solution(object):
    def findCheapestPrice(self, n, flights, src, dst, K):
        """
        :type n: int
        :type flights: List[List[int]]
        :type src: int
        :type dst: int
        :type K: int
        :rtype: int
        """
        graph = defaultdict(dict)
        for u, v, w in flights:
            graph[u][v] = w
        
        h = [(0, src, K)]
        while h:
            curP, city, stops = heapq.heappop(h)
            if city == dst:
                return curP
            if stops >=0:
                for next, p in graph[city].items():
                    heapq.heappush(h, (curP+p, next, stops-1))
                    
        return -1
