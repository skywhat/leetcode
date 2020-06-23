class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        if len(intervals) < 2:
            return 0
        ins = sorted(intervals, key= lambda x:x[1])
        start, res = ins[0], 0
        for i in range(1, len(ins)):
            if ins[i][0] < start[1]:
                res +=1
            else:
                start = ins[i]
        return res
