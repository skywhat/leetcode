class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        N = len(grid)
        dp = [[[-float('inf')]*N for _ in range(N)] for _ in range(N)]
        dp[0][0][0] = grid[0][0]

        # x1+y1 = x2+y2
        for x1 in range(N):
            for y1 in range(N):
                for x2 in range(N):
                    y2 = x1+y1-x2
                    if y2 <0 or y2>=N or grid[x1][y1] == -1 or grid[x2][y2] == -1:
                        continue
                    current_cherry = grid[x1][y1] + grid[x2][y2]
                    if x1 == x2:
                        current_cherry = grid[x1][y1]
                    for prev_x1, prev_x2 in [[x1, x2], [x1-1, x2], [x1, x2-1], [x1-1, x2-1]]:
                        prev_y1 = x1+y1-prev_x1-1
                        if 0<=prev_x1<N and 0<=prev_x1<N and 0<=prev_y1<N:
                            dp[x1][y1][x2] = max(dp[x1][y1][x2], dp[prev_x1][prev_y1][prev_x2] + current_cherry)
        
        return max(0, dp[-1][-1][-1])


"""
High-Level Explanation of the Approach:
Key idea:
Instead of two separate paths (down-right and then up-left), consider two simultaneous paths going from (0,0) to (N-1,N-1) moving only right or down.

This is valid because going down-right and then up-left is equivalent to two independent paths from (0,0) to (N-1,N-1).

Representation:
Use a 3D DP array:

dp[x1][y1][x2]
Here, (x1,y1) is the position of the first person and (x2,y2) (with y2 = x1 + y1 - x2) is the second person’s position. The sum x1 + y1 = x2 + y2 because both are taking the same number of steps simultaneously.

Why 3D?
The positions are not independent: after exactly t moves, the total distance traveled for both paths is the same (x1+y1 = x2+y2). Hence, we can derive one coordinate from the others.


Step-by-step breakdown of the code:
Initialization:

Start with all DP values as negative infinity, indicating unvisited or invalid paths.

Initialize the starting position dp[0][0][0] as the cherry count at the first cell (0,0).

Main Loops (x1, y1, x2):

Iterate over every combination of positions (x1,y1) and (x2,y2) reachable by moving down/right.

Coordinate Constraints:

y2 is derived as x1 + y1 - x2.

If y2 is out of bounds or either position is blocked (-1), skip.

Cherry Counting:

If both paths land on the same cell (x1,y1 == x2,y2), count cherries only once.

If positions differ, sum cherries from both cells.

DP Transition:

Consider previous positions that could have led to the current positions:

(x1-1,y1), (x2-1,y2)

(x1-1,y1), (x2,y2-1)

(x1,y1-1), (x2-1,y2)

(x1,y1-1), (x2,y2-1)

Update dp[x1][y1][x2] with the maximum cherries from previous states.

Result:

The final answer is the maximum cherries picked at positions (N-1,N-1) for both paths, or 0 if no path exists.


"""