class Solution(object):
    def mostVisitedPattern(self, username, timestamp, website):
        """
        :type username: List[str]
        :type timestamp: List[int]
        :type website: List[str]
        :rtype: List[str]
        """
        packedTups = sorted(zip(timestamp, username, website))
        userDict = defaultdict(list)
        for t in packedTups:
            userDict[t[1]].append([t[0], t[2]])
        count = defaultdict(int)
        maxFeq = 0
        res = None
        for user, hist in userDict.items():
            pages =[p[1] for p in hist]
            seqs = set(itertools.combinations(pages, 3))
            for seq in seqs:
                count[seq] +=1
                if count[seq] > maxFeq or (count[seq] == maxFeq and seq < res):
                    maxFeq = count[seq]
                    res = seq
        return res
