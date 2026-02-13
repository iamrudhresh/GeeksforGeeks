class Solution:
    def minTime (self, arr, k):
        # code here
        def ok(mi):
            i = 0
            s = 0
            cnt = 0
            while i < len(arr):
                while i < len(arr) and arr[i] + s <= mi:
                    s += arr[i]
                    i += 1
                cnt += 1
                s = 0
     
            return cnt <= k
            
        lo, hi = max(arr), sum(arr)
        while lo < hi:
            mi = lo + (hi-lo)//2
            if ok(mi):
                hi = mi
            else:
                lo = mi+1
        return lo
        