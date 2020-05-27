class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        seen = set()
        while n not in seen:
            seen.add(n)
            n = sum([int(i)**2 for i in str(n)])
            if n == 1:
                return True
        return False
