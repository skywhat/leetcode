class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        a = b = 0
        ms = defaultdict(int)
        mg = defaultdict(int)
        cnt = defaultdict(int)
        for i, x in enumerate(secret):
            if x == guess[i]:
                a +=1
            else:
                ms[x]+=1
                mg[guess[i]]+=1
        for k in ms:
            b += min(ms[k], mg[k])
        return str(a)+"A"+str(b)+"B"
