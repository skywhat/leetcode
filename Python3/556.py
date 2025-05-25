# 54321
# if every digit is greater than its right one, it has no next greater element.
# 12345, next greater one is 12354
# 534976
# 5 3 4 9 7 6
# from right to left, find the first digit 4, smaller than its right one.
# split the number into three parts, left = 53, pivot = 4, right = 976
# from right, find the smallest one greater than pivot, which is 6, swap them, now three parts are
# left = 53, pivot = 6, right = 974, reverse right = 479
# combine them to new number 536479, the next greater element.

class Solution:
    def nextGreaterElement(self, n: int) -> int:
        digits = [int(x) for x in list(str(n))]
        idx = len(digits)-2
        while idx >= 0:
            if digits[idx] < digits[idx+1]:
                break
            idx -=1
        if idx == -1:
            return -1
        left = digits[:idx]
        pivot = digits[idx]
        right = digits[idx+1:]

        cdd_idx = 0
        for i in range(len(right)):
            if right[i] > pivot:
                cdd_idx = i
            else:
                break

        pivot, right[cdd_idx] = right[cdd_idx], pivot

        new_digits = left + [pivot] + right[::-1]
        new_number = 0
        for x in new_digits:
            new_number = new_number*10 + x

        return new_number if new_number <= (2**31-1) else -1
