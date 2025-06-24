class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = defaultdict(list)
        for a, b in sorted(tickets)[::-1]:
            graph[a].append(b)
        
        def dfs(start, res):
            while graph[start]:
                dfs(graph[start].pop(), res)
            res.append(start)
        
        res = []
        dfs("JFK", res)
        return list(reversed(res))

"""
Here is some points to understand this algs and hope it helps.

In Eulerian paths, there must exist a start node(which is JFK in this problem) and a end node.
End node can be start node or another node.
end node is start node iff all nodes has even degree.
end node is another node iff there is another odd degree node and start node has an odd degree.
So, the algorithm is to find the end node first and delete the path to this node(backtrack)

"""
