# Solution 1: just use dictionary to store the word and count, and use heap to get the top 3 words.
class AutocompleteSystem:

    def __init__(self, sentences: List[str], times: List[int]):
        self.wordscount = defaultdict(int)
        for i in range(len(sentences)):
            self.wordscount[sentences[i]] = times[i]
        self.word = ""
        self.topsize = 3

    def input(self, c: str) -> List[str]:
        if c == "#":
            self.wordscount[self.word] +=1
            self.word = ""
            return []
        self.word = self.word + c
        h = []
        for word, cnt in self.wordscount.items():
            if word.startswith(self.word):
                heapq.heappush(h, self.Item(word, cnt))
                if len(h) > self.topsize:
                    heapq.heappop(h)
        res = []
        while h:
            res.append(heapq.heappop(h).word)
        return res[::-1]
    
    class Item:
        def __init__(self, word, cnt):
            self.word = word
            self.cnt = cnt
        def __lt__(self, other):
            if self.cnt == other.cnt:
                # it is a min heap, so if the count is the same, 
                # we need to pop out the larger word first, keep the smaller word in the heap.
                return self.word > other.word
            # if the count is different, we need to pop out the smaller count first, keep the larger count in the heap.
            return self.cnt < other.cnt



# Your AutocompleteSystem object will be instantiated and called as such:
# obj = AutocompleteSystem(sentences, times)
# param_1 = obj.input(c)


# Solution 2: use trie to store the word and count, and use heap to get the top 3 words.
class AutocompleteSystem:
    class TrieNode:
        def __init__(self):
            self.next = {}
            self.cnt = 0

    def __init__(self, sentences: List[str], times: List[int]):
        self.root = self.TrieNode()
        for i in range(len(sentences)):
            self._insertWord(sentences[i], times[i])
        self.topsize = 3
        self.word = ""
    
    def _insertWord(self, word, cnt):
        cur = self.root
        for c in word:
            if c not in cur.next:
                cur.next[c] = self.TrieNode()
            cur = cur.next[c]
        cur.cnt += cnt

    def input(self, c: str) -> List[str]:
        if c == "#":
            self._insertWord(self.word, 1)
            self.word = ""
            return []
        res = []
        cur = self.root
        self.word += c
        for c in self.word:
            if c not in cur.next:
                return []
            cur = cur.next[c]
        
        h = []
        self._collect(cur, h, self.word)
        while h:
            res.append(heapq.heappop(h).word)
        return res[::-1]

    def _collect(self, root, h, path):
        if root.cnt != 0:
            heapq.heappush(h, self.Item(path, root.cnt))
            if len(h) > self.topsize:
                heapq.heappop(h)
        for c in root.next:
            self._collect(root.next[c], h, path + c)
    
    class Item:
        def __init__(self, word, cnt):
            self.word = word
            self.cnt = cnt
        def __lt__(self, other):
            if self.cnt == other.cnt:
                return self.word > other.word
            return self.cnt < other.cnt

        

# Your AutocompleteSystem object will be instantiated and called as such:
# obj = AutocompleteSystem(sentences, times)
# param_1 = obj.input(c)