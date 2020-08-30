class Solution(object):
    def isReflected(self, points):
        """
        :type points: List[List[int]]
        :rtype: bool
        """
        minX, maxX = float("inf"), float("-inf")
        all = set()
        for p in points:
            minX = min(minX, p[0])
            maxX = max(maxX, p[0])
            all.add(tuple(p))
        
        for p in points:
            if (minX+maxX-p[0], p[1]) not in all:
                return False
        return True
