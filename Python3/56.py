class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        inters = sorted(intervals)

        start, end = inters[0]
        res = []
        for x, y in inters:
            if end < x:
                res.append([start, end])
                start, end = x, y
            else:
                end = max(end, y)
        return res + [[start, end]]
