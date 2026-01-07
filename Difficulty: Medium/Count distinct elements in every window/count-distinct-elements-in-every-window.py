from collections import defaultdict
class Solution:
    def countDistinct(self, arr, k):
        d=defaultdict(int)
        for i in range(k):
            d[arr[i]]+=1
        curr_count=len(d)
        res=[curr_count]
        for i in range(k,len(arr)):
            d[arr[i-k]]-=1
            if d[arr[i-k]]==0:
                curr_count-=1
            d[arr[i]]+=1
            if d[arr[i]]==1:
                curr_count+=1
            res.append(curr_count)
        return res