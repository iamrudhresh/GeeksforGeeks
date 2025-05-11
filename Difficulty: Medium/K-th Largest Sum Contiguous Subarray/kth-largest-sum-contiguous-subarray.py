from typing import List


class Solution:
    def kthLargest(self, arr, k) -> int:
        # code here
        heap=[]
        for i in range(len(arr)):
            c=0
            for j in range(i,len(arr)):
                c+=arr[j]
                heapq.heappush(heap,c)
                if len(heap)>k:
                    heapq.heappop(heap)
        return heap[0]



#{ 
 # Driver Code Starts
#Initial Template for Python 3
import heapq

# Position this line where user code will be pasted.

#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        k = int(input())
        ob = Solution()
        res = ob.kthLargest(arr, k)
        print(res)
        print("~")
        t -= 1

# } Driver Code Ends