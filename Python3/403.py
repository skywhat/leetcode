class Solution:
    def canCross(self, stones: List[int]) -> bool:
        """
        index 0: step = 1, so at most
        index 1: step = 2
        index n-1: step = n
        """
        n = len(stones)
        print(n)
        dp = [[False]*(n+1) for _ in range(n)]
        dp[0][1] = True

        for i in range(1, n):
            for j in range(i):
                dist = stones[i]-stones[j]
                if dist <0 or dist > n or not dp[j][dist]:
                    continue
                dp[i][dist] = True
                if dist >= 1:
                    dp[i][dist-1] = True
                if dist + 1 <= n:
                    dp[i][dist+1] = True
                if i == n -1:
                    return True
        return False
    
    """
    explanation:

                    +----+    +----+        +----+     +----+       
stone:          | S1 |    | S2 |        | S3 |     | S4 | 
            ____|____|____|____|________|____|_____|____|____________
           ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
position:"         0         1             3          5             "        

jump size:         1     [0, 1, 2]     [1, 2, 3]

// Suppose we want to know if the frog can reach stone 2 (S2),
// and we know the frog must come from S1, 
// dist(S1->S2) = 1 - 0 = 1, and we already know the frog is able to make a jump of size 1 at S1.
// Hence, the frog is able to reach S2, and the next jump would be 0, 1 or 2 units.


// Then, we want to know if the frog can reach stone 3 (S3),
// we know the frog must be at either S1 or S2 before reaching S3,

// If the frog comes from S1, then 
// we know dist(S1->S3) = 3 - 0 = 3, and we know frog couldn't make a jump of size 3 at S1.
// So it is not possible the frog can jump from S1 to S3.

// If the frog comes from S2, then
// we know dist(S2->S3) = 3 - 1 = 2, and we know frog could make a jump of size 2 at S2.
// Hence, the frog is able to reach S3, and the next jump would be 1, 2 or 3 units.

// If we repeat doing this for the rest stones, we'll end with something like below:
Exapme 1:
            
index:        0   1   2   3   4   5   6   7 
            +---+---+---+---+---+---+---+---+
stone pos:  | 0 | 1 | 3 | 5 | 6 | 8 | 12| 17|
            +---+---+---+---+---+---+---+---+
k:          | 1 | 0 | 1 | 1 | 0 | 1 | 3 | 5 |
            |   | 1 | 2 | 2 | 1 | 2 | 4 | 6 |
            |   | 2 | 3 | 3 | 2 | 3 | 5 | 7 |
            |   |   |   |   | 3 | 4 |   |   |
            |   |   |   |   | 4 |   |   |   |
            |   |   |   |   |   |   |   |   |

// Sub-problem and state:
let dp(i) denote a set containing all next jump size at stone i

// Recurrence relation:
for any j < i,
dist = stones[i] - stones[j];
if dist is in dp(j):
    put dist - 1, dist, dist + 1 into dp(i). 

// Now lets make this approach more efficient.
// BECAUSE 
// 1. The number of stones is ≥ 2 and is < 1,100. 
// 2. The frog is on the first stone and assume the first jump must be 1 unit.
// 3. If the frog's last jump was k units, then its next jump must be either k - 1, k, or k + 1 units,

// The maximum jump size the frog can make at each stone if possible is shown as followings: 
// stone:      0, 1, 2, 3, 4, 5
// jump size:  1, 2, 3, 4, 5, 6 (suppose frog made jump with size k + 1 at each stone)

// So instead of creating a HashSet for lookup for each stone, 
// we can create a boolean array with size of N + 1 (N is the number of stones),
// Like in the given example, at stone 2 the next jump could be 1, 2, 3, 
// we can use a bool array to represent this like
// index:    0  1  2  3  4  5  6  7  ...
//          [0, 1, 1, 1, 0, 0, 0, 0, ...]
// index is jump size, boolean value represents if the frog can make this jump.

// Then, the 2D array will be something like below.

index:        0   1   2   3   4   5   6   7 
            +---+---+---+---+---+---+---+---+
stone pos:  | 0 | 1 | 3 | 5 | 6 | 8 | 12| 17|
            +---+---+---+---+---+---+---+---+
k:        0 | 0 | 1 | 0 | 0 | 1 | 0 | 0 | 0 |
          1 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | 0 |
          2 | 0 | 1 | 1 | 1 | 1 | 1 | 0 | 0 |
          3 | 0 | 0 | 1 | 1 | 1 | 1 | 1 | 0 |
          4 | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 0 |
          5 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 1 |
          6 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |
          7 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |

// Sub-problem and state:
let dp[i][j] denote at stone i, the frog can or cannot make jump of size j

// Recurrence relation:
for any j < i,
dist = stones[i] - stones[j];
if dp[j][dist]:
    dp[i][dist - 1] = ture
    dp[i][dist] = ture
    dp[i][dist + 1] = ture
    
    """