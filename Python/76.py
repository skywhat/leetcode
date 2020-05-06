class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        start = end = minStart= 0
        cnt = len(t)
        chardict = dict()
        for c in t:
            chardict[c] = chardict.get(c, 0) + 1
        minLen = len(s)+1
        
        while end < len(s):
            chardict[s[end]] = chardict.get(s[end], 0) -1
            if chardict[s[end]] >= 0:
                cnt -=1
            end +=1
            while cnt == 0:
                if (end-start) < minLen:
                    minStart = start
                    minLen = end-start
                chardict[s[start]] = chardict.get(s[start], 0) +1
                if chardict[s[start]] > 0:
                    cnt +=1
                start +=1
        return s[minStart:minStart+minLen] if minLen !=len(s)+1 else ""            
        
