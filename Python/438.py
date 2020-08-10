class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        m, n = len(s), len(p)
        if m < n:
            return []
        pcount = collections.Counter(p)
        scount = collections.Counter(s[:n])
        res = []
        if pcount == scount:
            res.append(0)
        for i in range(n, m):
            if s[i] not in scount:
                scount[s[i]] = 1
            else:
                scount[s[i]] +=1
            scount[s[i-n]] -=1
            if scount[s[i-n]] == 0:
                del scount[s[i-n]]
            if pcount == scount:
                res.append(i-n+1)
        return res
