class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n == 1:
            return "1"
        sayn_1 = self.countAndSay(n-1)
        res = ""
        cnt = 1
        for i in range(1, len(sayn_1)):
            if sayn_1[i] == sayn_1[i-1]:
                cnt += 1
            else:
                res += str(cnt) + sayn_1[i-1]
                cnt =1
        res += str(cnt) + sayn_1[-1]
        return res
