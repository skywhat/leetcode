class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        sumgas = sumcost = tank = start = 0
        for i in range(len(gas)):
            sumgas += gas[i]
            sumcost += cost[i]
            tank += gas[i] - cost[i]
            if tank < 0:
                start = i+1
                tank = 0
        return start if sumgas >= sumcost else -1
