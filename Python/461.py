class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        z = x^y
        count = 0
        while z>0:
            if z%2:
                count+=1
            z /= 2
        return count
