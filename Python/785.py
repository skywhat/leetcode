class Solution(object):
    def isBipartite(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: bool
        """        
        colors = {}
        for i in range(len(graph)):
            if i in colors:
                continue
            q = deque([i])
            colors[i] = 0
            
            while q:
                cur = q.popleft()
                for ne in graph[cur]:
                    if ne not in colors:
                        colors[ne] = 1- colors[cur]
                        q.append(ne)
                    elif colors[ne] == colors[cur]:
                        return False
        return True
