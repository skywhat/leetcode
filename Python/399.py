class Solution(object):
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        def dfs(start, end, val, seen):
            if start in seen or start not in graph:
                return -1.0 
            if start == end:
                return val
            seen.add(start)
            for key, v in graph[start].items():
                res = dfs(key, end, val*v, seen)
                if res != -1:
                    return res
            return -1
        
        graph = collections.defaultdict(dict)
        for i in range(len(equations)):
            graph[equations[i][0]][equations[i][1]] = values[i]
            graph[equations[i][1]][equations[i][0]] = 1/values[i]
        res = []
        for q in queries:
            res.append(dfs(q[0], q[1], 1.0, set()))
        return res
