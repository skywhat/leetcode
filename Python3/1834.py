class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        avail = [] # (processingTime, index)
        n = len(tasks)
        sorted_tasks = sorted([t[0], t[1], i] for i, t in enumerate(tasks))
        res = []
        i = 0
        current = sorted_tasks[0][0]
        while len(res) < n:
            while i<n and sorted_tasks[i][0] <= current:
                heapq.heappush(avail, (sorted_tasks[i][1], sorted_tasks[i][2]))
                i+=1
            if avail:
                process, index = heapq.heappop(avail)
                res.append(index)
                current += process
            elif i<n and current < sorted_tasks[i][0]:
                current = sorted_tasks[i][0]

        return res
