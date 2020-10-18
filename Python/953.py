class Solution(object):
    def isAlienSorted(self, words, order):
        """
        :type words: List[str]
        :type order: str
        :rtype: bool
        """
        orderList = [0]*26
        for i, c in enumerate(order):
            orderList[ord(c)-ord('a')] = i
        prev = ""
        for w in words:
            if len(prev) > len(w) and prev.startswith(w):
                return False
            for i in range(min(len(w), len(prev))):
                if w[i] != prev[i]:
                    posw = orderList[ord(w[i]) - ord('a')]
                    posp = orderList[ord(prev[i]) - ord('a')]
                    if posw < posp:
                        return False
                    break
            prev = w
        return True
