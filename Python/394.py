class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        numStack = []
        strStack = []
        n = 0
        t = ""
        for c in s:
            if c.isdigit():
                n = n*10 + int(c)
            elif c == "[":
                numStack.append(n)
                strStack.append(t)
                t = ""
                n = 0
            elif c == "]":
                t = strStack.pop() + t*numStack.pop()
            else:
                t +=c
        return t

class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        i = 0
        res, _  = self.decodeStartFrom(s, i)
        return res

    def decodeStartFrom(self, s, i):
        res = ""
        n = 0
        while i < len(s):
            if s[i].isdigit():
                n = n*10 + int(s[i])
            elif s[i].isalpha():
                res += s[i]
            elif s[i] == "[":
                t, i = self.decodeStartFrom(s, i+1)
                res += n*t
                n = 0
            elif s[i] == "]":
                return res, i
            i +=1
        return res, len(s)
