class Solution:
    def constructArr(self, arr):
        from math import isqrt
        m = len(arr)
        if m == 0:
            return [1]
        if m == 1:
            return [1, arr[0] - 1]
        n = isqrt(m * 2) + 1
        a12 = arr[0]
        a13 = arr[1]
        a23 = arr[n - 1]
        a1 = (a12 + a13 - a23) // 2
        original = [a1]
        original.extend(arr[i] - a1 for i in range(n - 1))
        return original