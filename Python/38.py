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

class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        res = ""
        for i in range(1, n+1):
            res = self.Say(res)
        return res
    
    def Say(self, s):
        if s == "":
            return "1"
        res = ""
        pos = 0
        for i in range(1, len(s)):
            if s[i] != s[pos]:
                res += str(i-pos) + s[pos]
                c = s[i]
                pos = i
        res += str(len(s)-pos) + s[-1]
        return res
        
