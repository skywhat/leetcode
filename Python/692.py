# custom the sort in heap.
class Item(object):
    def __init__(self, word, cnt):
        self.word = word
        self.cnt = cnt
    
    def __equal__(self, other):
        return self.word == other.word and self.cnt == other.cnt

    def __lt__(self, other):
        if self.cnt == other.cnt:
            return self.word > other.word
        return self.cnt < other.cnt

class Solution(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        c = collections.Counter(words)
        h = []
        for key in c:
            heapq.heappush(h, Item(key, c[key]))
            if len(h) > k:
                heapq.heappop(h)
        res = []
        while h:
            item = heapq.heappop(h)
            res.append(item.word)
        return list(reversed(res))


class Solution(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        c = collections.Counter(words)
        h = []
        for key in c:
            heapq.heappush(h, [-c[key], key])
        res = []
        for i in range(k):
            _, s = heapq.heappop(h)
            res.append(s)
        return res
