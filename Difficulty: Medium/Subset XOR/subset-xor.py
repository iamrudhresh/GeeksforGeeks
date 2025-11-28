class Solution:
    def subsetXOR(self, n : int):
        # code here
        from functools import reduce
        from operator import xor
        acc = reduce(xor, range(1, n+1))
        if acc == n:
            return list(range(1, n+1))
        missing_x = acc ^ n
        return [e for e in range(1, n+1) if e != missing_x]

