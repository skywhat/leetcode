class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 2:
            return 0
        prime = [True]*n
        prime[0] = prime[1] = False
        for i in range(2, n):
            if prime[i]:
                j = 2
                while i*j<n:
                    prime[i*j] = False
                    j+=1
        return prime.count(True)
