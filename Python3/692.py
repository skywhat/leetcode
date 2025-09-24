class Solution:
    class Pair:
        def __init__(self, word, freq):
            self.word = word
            self.freq = freq
        def __lt__(self, other):
            if self.freq == other.freq:
                return self.word > other.word
            return self.freq < other.freq

    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        count = Counter(words)
        h = []
        for word, freq in count.items():
            pair = self.Pair(word, freq)
            heapq.heappush(h, pair)
            if len(h) > k:
                heapq.heappop(h)
        items = []
        while h:
            items.append(heapq.heappop(h).word)
        return items[::-1]
