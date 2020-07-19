class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        res = [0]*n
        bst = []
        for i in range(n-1, -1, -1):
            left, right = 0, len(bst)
            while left<right:
                mid = (left+right)/2
                if bst[mid] < nums[i]:
                    left = mid+1
                else:
                    right = mid
            res[i] = right
            bst.insert(right, nums[i])
        return res

# Merge sort
class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = [0]*len(nums)
        s = []
        for i, x in enumerate(nums):
            s.append((x, i))
        self.mergeSort(s, 0, len(s)-1, res)
        return res

    def mergeSort(self, s, l, r, res):
        if l>=r:
            return
        mid = (l+r)/2
        self.mergeSort(s, l, mid, res)
        self.mergeSort(s, mid+1, r, res)
        self.merge(s, l, mid, r, res)

    def merge(self, s, l, mid, r, res):
        i, j = l, mid+1
        num_of_right_lt_left = 0
        t = []
        while i<=mid and j<=r:
            if s[i][0] <= s[j][0]:
                t.append(s[i])
                res[s[i][1]] += num_of_right_lt_left
                i+=1
            else:
                t.append(s[j])
                num_of_right_lt_left +=1
                j+=1
        while i<=mid:
            t.append(s[i])
            res[s[i][1]] += num_of_right_lt_left
            i+=1
        while j<=r:
            t.append(s[j])
            j+=1
        for i, x in enumerate(t):
            s[l+i] = x


