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


Example:
JFK: A, D
A: C
B: C
C: D, JFK
D: A, B


From JFK we first visit JFK -> A -> C -> D -> A. There we're stuck, so we write down A as the end of the route and retreat back to D. There we see the unused ticket to B and follow it: D -> B -> C -> JFK -> D. Then we're stuck again, retreat and write down the airports while doing so: Write down D before the already written A, then JFK before the D, etc. When we're back from our cycle at D, the written route is D -> B -> C -> JFK -> D -> A. Then we retreat further along the original path, prepending C, A and finally JFK to the route, ending up with the route JFK -> A -> C -> D -> B -> C -> JFK -> D -> A.


"""
