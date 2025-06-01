class Solution:
    def nearestPalindromic(self, n: str) -> str:
        n_len = len(n)
        root = int(n[:(n_len+1)//2] if n_len&1 else n[:n_len//2])
        candidates = []
        for new_root in [root, root+1, root-1]:
            candidates.append(self._build_new_number(new_root, n_len&1))
        #edge cases
        candidates.append(str(10**n_len+1))
        candidates.append(str(10**n_len-1))
        candidates.append(str(10**(n_len-1)+1))
        candidates.append(str(10**(n_len-1)-1))

        res = '0'
        for c in candidates:
            if c != n and (self._delta(n, c) < self._delta(n, res) or (self._delta(n, c) == self._delta(n, res) and int(c) < int(res))):
                res = c
        return res

    def _delta(self, a, b):
        return abs(int(a) - int(b))

    def _build_new_number(self, root, odd):
        rootstr = str(root)
        if odd:
            return rootstr + rootstr[:-1][::-1]
        return rootstr + rootstr[::-1]
