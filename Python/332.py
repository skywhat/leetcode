#sorted graph
class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        graph = defaultdict(list)
        for a, b in sorted(tickets)[::-1]:
            graph[a].append(b)

        s = ["JFK"]
        res = []

        while s:
            start = s[-1]
            if graph[start] == list():
                res.append(start)
                s.pop()
            else:
                s.append(graph[start][-1])
                graph[start].pop()
        return res[::-1]

# multiset using Counter
class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        graph = defaultdict(Counter)
        for a, b in tickets:
            graph[a][b] +=1

        s = ["JFK"]
        res = []
        while s:
            if graph[s[-1]] == Counter():
                res.append(s.pop())
            else:
                nexts = sorted(list(graph[s[-1]]))
                graph[s[-1]][nexts[0]] -=1
                if graph[s[-1]][nexts[0]] == 0:
                    del graph[s[-1]][nexts[0]]
                s.append(nexts[0])

        return res[::-1]

#dfs
class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        graph = defaultdict(list)
        for a, b in sorted(tickets)[::-1]:
            graph[a].append(b)

        res = []

        def dfs(start, graph, res):
            while graph[start]:
                dfs(graph[start].pop(), graph, res)
            res.append(start)

        dfs("JFK", graph, res)
        return res[::-1]
