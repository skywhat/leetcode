class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        degree = [0]*numCourses
        for p in prerequisites:
            degree[p[0]] +=1
        
        q = deque()
        for i, d in enumerate(degree):
            if d == 0:
                q.append(i)
        
        res = []
        
        while q:
            c = q.popleft()
            res.append(c)
            
            for p in prerequisites:
                if p[1] == c:
                    p[1] = -1
                    degree[p[0]] -=1
                    if degree[p[0]] == 0:
                        q.append(p[0])
                    
        
        return res if len(res) == numCourses else []
