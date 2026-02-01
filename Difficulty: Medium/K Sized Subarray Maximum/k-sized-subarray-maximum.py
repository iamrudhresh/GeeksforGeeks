class Solution:
    def maxOfSubarrays(self, arr, k):
        ret=[]
        stk=deque()
        for ix,ve in enumerate(arr):
            while stk and arr[stk[-1]]<=ve:
                stk.pop()
            stk.append(ix)
            if ix<k-1:
                continue
            while stk and stk[0]<ix-k+1:
                stk.popleft()
            ret.append(arr[stk[0]])
        return ret