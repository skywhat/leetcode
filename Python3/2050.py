class Solution:
    def minimumTime(self, n: int, relations: List[List[int]], time: List[int]) -> int:
        graph = defaultdict(set)
        indegree = [0]*(n+1)
        for x, y in relations:
            graph[x].add(y)
            indegree[y] +=1
        
        h = []
        for i in range(1, n+1):
            if indegree[i] == 0:
                heapq.heappush(h, (time[i-1], i))
        res = 0
        while h:
            endtime, i = heapq.heappop(h)
            for next in graph[i]:
                indegree[next] -=1
                if indegree[next] == 0:
                    heapq.heappush(h, (endtime + time[next-1], next))
            res = endtime
        return res
