class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        res = []
        start, end = newInterval[0], newInterval[1]
        i = 0
        while i<len(intervals):
            if intervals[i][0] < start:
                res.append(intervals[i])
            else:
                break
            i+=1
        
        if res and res[-1][1] >= start:
            res[-1][1] = max(end, res[-1][1])
        else:
            res.append(newInterval)
        
        while i<len(intervals):
            if res[-1][1] >= intervals[i][0]:
                res[-1][1] = max(res[-1][1], intervals[i][1])
            else:
                res.append(intervals[i])
            i+=1
        return res
