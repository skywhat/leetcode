class Node(object):
    def __init__(self, start, end, sum):
        self.start = start
        self.end = end
        self.sum = sum
        self.left = self.right = None

class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.root = self._buildTree(nums, 0, len(nums)-1)
    
    def _buildTree(self, nums, i, j):
        if i>j:
            return None
        if i == j:
            return Node(i, j, nums[i])
        sum = 0
        mid = (i+j)/2
        left = self._buildTree(nums, i, mid)
        right = self._buildTree(nums, mid+1, j)
        sum = left.sum + right.sum
        root = Node(i, j, sum)
        root.left = left
        root.right = right
        return root
        

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: None
        """
        self._updateTree(i, val, self.root)
    
    def _updateTree(self, i, val, root):
        if not root:
            return 0
        if root.start == i and root.end == i:
            diff = val - root.sum
            root.sum = val
            return diff
        mid = (root.start + root.end)/2
        diff = 0
        if i<=mid:
            diff = self._updateTree(i, val, root.left)
        else:
            diff = self._updateTree(i, val, root.right)
        root.sum += diff
        return diff

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self._getSum(i, j, self.root)
        
    def _getSum(self, i, j, root):
        if i > root.end or j < root.start:
            return 0
        if i == root.start and j == root.end:
            return root.sum
        
        mid = (root.start+root.end)/2
        if j<= mid:
            return self._getSum(i, j, root.left)
        elif i>mid:
            return self._getSum(i, j, root.right)
        return self._getSum(i, mid, root.left) + self._getSum(mid+1, j, root.right)

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)
