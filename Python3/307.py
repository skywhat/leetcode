class NumArray:
    class Node:
        def __init__(self, start, end, val, left=None, right=None):
            self.start = start
            self.end = end
            self.val = val
            self.left = left
            self.right = right

    def __init__(self, nums: List[int]):
        self.root = self._buildSegmentTree(nums, 0, len(nums)-1)
    
    def _buildSegmentTree(self, nums, i, j):
        if i>j:
            return None
        if i == j:
            return self.Node(i, j, nums[i])
        mid = (i+j)//2
        left = self._buildSegmentTree(nums, i, mid)
        right = self._buildSegmentTree(nums, mid+1, j)
        val = 0
        if left:
            val += left.val
        if right:
            val += right.val
        return self.Node(i, j, val, left, right)
        

    def update(self, index: int, val: int) -> None:
        self._updateSegmentTree(self.root, index, val)
    
    def _updateSegmentTree(self, root, index, val):
        if not root:
            return 0
        if root.start == index and root.end == index:
            diff = val - root.val
            root.val = val
            return diff
        mid = (root.start+root.end)//2
        diff = 0
        if index <= mid:
            diff = self._updateSegmentTree(root.left, index, val)
        else:
            diff = self._updateSegmentTree(root.right, index, val)
        root.val += diff
        return diff
        

    def sumRange(self, left: int, right: int) -> int:
        return self._find(self.root, left, right)

    def _find(self, root, i, j):
        if root.start == i and root.end == j:
            return root.val
        mid = (root.start+root.end)//2
        if j<=mid:
            return self._find(root.left, i, j)
        if i>mid:
            return self._find(root.right, i, j)
        return self._find(root.left, i, mid) + self._find(root.right, mid+1, j)



# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)
