class Solution:
    def maxAmount(self, initialCurrency: str, pairs1: List[List[str]], rates1: List[float], pairs2: List[List[str]], rates2: List[float]) -> float:
        most = Counter({initialCurrency: 1.0})
        currset = set()
        for a, b in pairs1:
            currset.add(a)
            currset.add(b)
        # bellman-ford algorithm, https://www.geeksforgeeks.org/bellman-ford-algorithm-in-python/
        # by traversing all edges |V| - 1 times, where |V| is the number of vertices
        for _ in range(len(currset)-1):
            for i in range(len(pairs1)):
                a, b = pairs1[i]
                rate = rates1[i]
                most[a] = max(most[a], most[b]*(1/rate))
                most[b] = max(most[b], most[a]*rate)
        currset.clear()
        for a, b, in pairs2:
            currset.add(a)
            currset.add(b)
        for _ in range(len(currset)-1):
            for i in range(len(pairs2)):
                a, b = pairs2[i]
                rate = rates2[i]
                most[a] = max(most[a], most[b]*(1/rate))
                most[b] = max(most[b], most[a]*rate)
        return most[initialCurrency]

