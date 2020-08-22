class Solution(object):
    def numRabbits(self, answers):
        """
        :type answers: List[int]
        :rtype: int
        """
        cnt = collections.Counter(answers)
        res = 0
        for x, n in cnt.items():
            if n%(x+1) == 0:
                res += n/(x+1)*(x+1)
            else:
                res += (n/(x+1)+1)*(x+1)
        return res
