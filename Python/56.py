class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        if len(intervals) <=1:
            return intervals
        intervals = sorted(intervals, key=lambda x:(x[0], x[1]))
        res = []
        i=0
        while i<len(intervals):
            start, end = intervals[i][0], intervals[i][1]
            j = i+1
            while j<len(intervals) and intervals[j][0] <=end:
                end = max(end, intervals[j][1])
                j+=1
            res.append([start, end])
            i=j
        return res
