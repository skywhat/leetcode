class Solution:
    def alienOrder(self, words: List[str]) -> str:
        suc = defaultdict(set)
        prev = defaultdict(set)
        all = set()
        s = ""
        for t in words:
            if len(s) > len(t) and s.startswith(t):
                return ""
            for i in range(min(len(s), len(t))):
                if s[i] != t[i]:
                    suc[s[i]].add(t[i])
                    prev[t[i]].add(s[i])
                    break
            for c in t:
                all.add(c)
            s = t
        cnt = len(all)
        for c in prev.keys():
            all.discard(c)

        res = ""
        while all:
            c = all.pop()
            res += c

            for next in suc[c]:
                prev[next].discard(c)
                if len(prev[next]) == 0:
                    all.add(next)
        return res if len(res) == cnt else ""

