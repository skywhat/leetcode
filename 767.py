class Solution(object):
    def reorganizeString(self, S):
        """
        :type S: str
        :rtype: str
        """
        count, n = defaultdict(int), len(S)
        for c in S:
            count[c] +=1
        ls = sorted(count.items(), key=lambda x:x[1] , reverse = True)
        if ls[0][1] > (n+1)/2:
            return ""
        res = [None]*n
        
        start = 0
        for e in ls:
            for i in range(e[1]):
                if start >= n:
                    start = 1
                res[start] = e[0]
                start +=2
        return "".join(res)

import heapq
class Solution(object):
    def reorganizeString(self, S):
        """
        :type S: str
        :rtype: str
        """
        if S == "":
            return ""
        count, n = defaultdict(int), len(S)
        for c in S:
            count[c] +=1
        h = []
        for key, val in count.items():
            heapq.heappush(h, [-val, key])
        pre = heapq.heappop(h)
        res = pre[1]
        while h:
            cur = heapq.heappop(h)
            if pre[0] < -1:
                heapq.heappush(h, [pre[0]+1, pre[1]])
            pre = cur
            res += pre[1]
        return res if len(res) == len(S) else ""
