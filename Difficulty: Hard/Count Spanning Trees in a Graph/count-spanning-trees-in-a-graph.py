class Solution:
    def countSpanTree(self, n, edges):
        import numpy as np
        l=np.zeros((n,n,))
        for sta,sto in edges:
            l[sta][sta]+=1
            l[sto][sto]+=1
            l[sta][sto]-=1
            l[sto][sta]-=1
        lr=l[:-1,:-1]
        return round(np.linalg.det(lr))