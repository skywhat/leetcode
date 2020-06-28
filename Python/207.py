class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        q = deque()
        degrees = [0]*numCourses
        for p in prerequisites:
            degrees[p[0]] +=1
        for i in range(numCourses):
            if degrees[i] == 0:
                q.append(i)
        cnt = 0
        while q:
            prer = q.popleft()
            cnt +=1
            for p in prerequisites:
                if p[1] == prer:
                    p[1] = -1
                    degrees[p[0]] -=1
                    if degrees[p[0]] == 0:
                        q.append(p[0])
        return cnt == numCourses



class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        graph = defaultdict(set)
        todo = {i:set() for i in range(numCourses)}
        for pre in prerequisites:
            graph[pre[1]].add(pre[0])
            todo[pre[0]].add(pre[1])

        q = deque()
        for t in todo:
            if todo[t] == set():
                q.append(t)

        while q:
            pre = q.popleft()
            for c in graph[pre]:
                todo[c].discard(pre)
                if todo[c] == set():
                    q.append(c)
            todo.pop(pre)
        return todo == {}
