class Solution(object):
    def stoneGame(self, piles):
        """
        :type piles: List[int]
        :rtype: bool
        """
        '''
dp[i][j] actually means maximum(alex stone - lee stone) and maximum(lee stone - alex stone)
alternatively, depending on who picks from piles[i]~piles[j] first.
If alex picks from piles[i]~piles[j] first, then dp[i][j] means maximum(alex stone - lee stone);
If Lee pick from piles[i]~piles[j] frist, then dp[i][j] means maximum(lee stone - alex stone) .
        '''
        n = len(piles)
        dp = [[0]*n for i in range(n)]
        for i in range(n):
            dp[i][i] = piles[i]
        for i in range(n-2, -1, -1):
            for j in range(i+1,n):
                dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1])
        return dp[0][n-1] > 0


class Solution(object):
    def stoneGame(self, piles):
        """
        :type piles: List[int]
        :rtype: bool
        """
        return True

        '''
If Alex wants to pick even indexed piles piles[0], piles[2], ....., piles[n-2],
he picks first piles[0], then Lee can pick either piles[1] or piles[n - 1].
Every turn, Alex can always pick even indexed piles and Lee can only pick odd indexed piles.

In the description, we know that sum(piles) is odd.
If sum(piles[even]) > sum(piles[odd]), Alex just picks all evens and wins.
If sum(piles[even]) < sum(piles[odd]), Alex just picks all odds and wins.

So, Alex always defeats Lee in this game.
        '''
