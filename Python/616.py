class Solution(object):
    def addBoldTag(self, s, dict):
        """
        :type s: str
        :type dict: List[str]
        :rtype: str
        """
        n = len(s)
        state = [False]*n
        end = 0
        for i in range(n):
            for word in dict:
                if s.startswith(word, i):
                    end = max(end, i+len(word))
                state[i] = end>i
        
        res = ""
        i = 0
        while i<n:
            if not state[i]:
                res = res + s[i]
                i+=1
            else:
                res = res + "<b>"
                while i<n and state[i]:
                    res = res + s[i]
                    i +=1
                res = res + "</b>"
        return res
