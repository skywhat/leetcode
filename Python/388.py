class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        dirs = input.split("\n")
        maxLen = 0
        pathlen = {0:0}
        for d in dirs:
            term = d.lstrip("\t")
            depth = len(d) - len(term)
            if "." in term:
                maxLen = max(maxLen, pathlen[depth] + len(term))
            else:
                pathlen[depth+1] = pathlen[depth] + 1 + len(term)
        return maxLen
