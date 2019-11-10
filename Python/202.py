class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        existingNums = []
        while True:
	        if n in existingNums:
		        return False
	        elif n == 1:
		        return True
	        existingNums.append(n)
	        n = self.sumSquare(n)
            
    def sumSquare(self, n):
	    res = 0
	    while n!=0:
		    res += (n%10)**2
		    n /=10
	    return res
