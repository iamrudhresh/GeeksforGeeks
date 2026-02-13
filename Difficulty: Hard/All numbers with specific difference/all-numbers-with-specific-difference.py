class Solution:
    def getCount(self, n, d):
        if n <= d:
            return 0
        lo, hi = 1, n + 1
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if mid - sum(map(int, str(mid))) >= d:
                hi = mid
            else:
                lo = mid + 1
        return n - lo + 1