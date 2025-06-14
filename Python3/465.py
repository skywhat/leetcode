class Solution:
    def minTransfers(self, transactions: List[List[int]]) -> int:
        money = defaultdict(int)
        for x, y, amount in transactions:
            # x gave person y
            money[x] -= amount
            money[y] += amount
        debts = []
        for person, amount in money.items():
            if amount != 0:
                debts.append(amount)
        
        def minTransaction(curId, debts):
            while curId < len(debts) and debts[curId] == 0:
                curId +=1
            if curId == len(debts):
                return 0
            res = float('inf')
            for i in range(curId+1, len(debts)):
                if debts[curId] * debts[i] < 0:
                    debts[i] += debts[curId]
                    res = min(res, minTransaction(curId+1, debts) + 1)
                    debts[i] -= debts[curId]
            return res
        
        return minTransaction(0, debts)

