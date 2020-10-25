class Solution(object):
    def differByOne(self, dict):
        """
        :type dict: List[str]
        :rtype: bool
        """
        n = len(dict[0])
        nwords = len(dict)
        for i in range(n):
            seen = set()
            for j in range(nwords):
                t = dict[j][:i] + "*" + dict[j][i+1:]
                if t in seen:
                    return True
                seen.add(t)
        return False
