"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        return self.helper(grid, 0, 0, len(grid))

    def helper(self, grid, i, j, n):
        if n < 1:
            return None
        if n == 1:
            return Node(grid[i][j], True, None, None, None, None)
        topLeft = self.helper(grid, i, j, n//2)
        topRight = self.helper(grid, i, j+n//2, n//2)
        bottomLeft = self.helper(grid, i+n//2, j, n//2)
        bottomRight = self.helper(grid, i+n//2, j+n//2, n//2)
        if topLeft.val == topRight.val and topRight.val == bottomLeft.val and bottomLeft.val == bottomRight.val and \
            topLeft.isLeaf and topRight.isLeaf and bottomLeft.isLeaf and bottomRight.isLeaf:
            return Node(grid[i][j], True, None, None, None, None)
        return Node(grid[i][j], False, topLeft, topRight, bottomLeft, bottomRight)

