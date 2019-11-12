class Solution(object):
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """
        s = set()
        for c in candies:
	        s.add(c)
        return min(len(s), len(candies)/2)
