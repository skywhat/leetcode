class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        people = sorted(people, key= lambda p:(-p[0], p[1]))
        res = []
        for p in people:
            res.insert(p[1], p)
        return res


class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(people)
        res = [[] for i in range(n)]
        heapq.heapify(people)
        while people:
            h, k = heapq.heappop(people)
            i = ge = 0
            while ge<k or res[i] != list():
                if res[i] == list() or res[i][0] >= h:
                    ge +=1
                i+=1
            res[i] = [h, k]
        return res
