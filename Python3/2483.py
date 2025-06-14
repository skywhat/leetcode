class Solution:
    def bestClosingTime(self, customers: str) -> int:
        totalN = totalY = 0
        n = len(customers)
        preY = [0]*n
        preN = [0]*n
        for i, c in enumerate(customers):
            if c == "Y":
                totalY+=1
            else:
                totalN+=1
            preY[i] = totalY
            preN[i] = totalN
        
        closeHour = 0
        minPenalty = n+1
        for i in range(n+1):
            if i>0:
                penalty = preN[i-1] + totalY - preY[i-1]
            else:
                penalty = totalY
            if penalty < minPenalty:
                minPenalty = penalty
                closeHour = i
        return closeHour
