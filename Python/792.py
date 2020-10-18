class Solution(object):
    def numMatchingSubseq(self, S, words):
        """
        :type S: str
        :type words: List[str]
        :rtype: int
        """
        d = defaultdict(list)
        for w in words:
            d[w[0]].append(w)
        
        cnt = 0
        for i, c in enumerate(S):
            ws = d[c]
            d[c] = []
            for w in ws:
                if len(w) == 1:
                    cnt +=1
                else:
                    d[w[1]].append(w[1:])
        return cnt
