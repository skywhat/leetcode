class Solution:
    def judgePoint24(self, cards: List[int]) -> bool:
        return self.dfs(cards)

    def dfs(self, cards):
        if len(cards) == 1:
            return abs(cards[0] - 24.0) <= 0.01
        n = len(cards)
        for i in range(n):
            for j in range(i):
                rest_cards = [cards[k] for k in range(n) if k !=i and k!=j]
                for candidate in self.next_candidate(cards[i], cards[j]):
                    rest_cards.append(candidate)
                    if self.dfs(rest_cards):
                        return True
                    rest_cards.pop()
        return False
        
    def next_candidate(self, a, b):
        cand = [a+b, a-b, b-a, a*b]
        if a:
            cand.append(b/a)
        if b:
            cand.append(a/b)
        return cand

