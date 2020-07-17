class AutocompleteSystem(object):

    def __init__(self, sentences, times):
        """
        :type sentences: List[str]
        :type times: List[int]
        """
        self.d = collections.defaultdict(int)
        for i, x in enumerate(sentences):
            self.d[x] = times[i]
        self.word = ""
        self.top_size = 3
        

    def input(self, c):
        """
        :type c: str
        :rtype: List[str]
        """
        if c == "#":
            self.d[self.word] +=1
            self.word = ""
            return []
        self.word += c
        h = []
        for w, t in self.d.items():
            if w.startswith(self.word):
                heapq.heappush(h, Item(w, t))
                if len(h) > self.top_size:
                    heapq.heappop(h)
        res = []
        while h:
            item = heapq.heappop(h)
            res.append(item.word)
        return list(reversed(res))
        
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
        


# Your AutocompleteSystem object will be instantiated and called as such:
# obj = AutocompleteSystem(sentences, times)
# param_1 = obj.input(c)



class TrieNode(object):
    def __init__(self):
        self.cnt = 0
        self.next = {}

class AutocompleteSystem(object):

    def __init__(self, sentences, times):
        """
        :type sentences: List[str]
        :type times: List[int]
        """
        self.root = TrieNode()
        self.d = collections.defaultdict(int)
        for i, words in enumerate(sentences):
            self.insertWords(words, times[i])

        self.word = ""
        self.top_size = 3

    def insertWords(self, words, cnt):
        cur = self.root
        for c in words:
            if c not in cur.next:
                cur.next[c] = TrieNode()
            cur =cur.next[c]
        cur.cnt += cnt


    def input(self, c):
        """
        :type c: str
        :rtype: List[str]
        """
        if c == "#":
            self.insertWords(self.word, 1)
            self.word = ""
            return []
        self.word +=c
        cur = self.root
        for c in self.word:
            if c not in cur.next:
                return []
            cur = cur.next[c]
        #collect all words
        h = []
        self.collect(cur, self.word, h)
        res = []
        while h:
            item = heapq.heappop(h)
            res.append(item.word)
        return list(reversed(res))

    def collect(self, root, s, h):
        if not root:
            return
        if root.cnt != 0:
            heapq.heappush(h, Item(s, root.cnt))
            if len(h) > self.top_size:
                heapq.heappop(h)
        for key in root.next:
            self.collect(root.next[key], s+key, h)


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



# Your AutocompleteSystem object will be instantiated and called as such:
# obj = AutocompleteSystem(sentences, times)
# param_1 = obj.input(c)
