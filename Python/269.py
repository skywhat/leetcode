class Solution(object):
    def alienOrder(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        suc = defaultdict(set)
        prev = defaultdict(set)
        all = set()
        s = ""
        
        for w in words:
            for i in range(min(len(s), len(w))):
                if len(s) > len(w) and s.startswith(w):
                    return ""
                if s[i] != w[i]:
                    suc[s[i]].add(w[i])
                    prev[w[i]].add(s[i])
                    break
            s = w
            for c in w:
                all.add(c)
                
        cnt = len(all)
        for c in prev.keys():
            all.discard(c)
        
        res = ""
        while all:
            x = next(iter(all))
            all.discard(x)
            res += x
            
            for nt in suc[x]:
                prev[nt].discard(x)
                if len(prev[nt]) == 0:
                    all.add(nt)
        return res if len(res) == cnt else ""
