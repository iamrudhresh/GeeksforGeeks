
class Solution:
    def maxWater(self, arr):
        # code here
          # code here
        n=len(arr)
        lmax = [arr[0]]*n
        rmax = [arr[n-1]]*n
        
        
        for i in range(1,n):
            if arr[i]>lmax[i-1]:
                lmax[i]=arr[i]
            else:
                lmax[i]=lmax[i-1]
        
        # print(lmax)
        
        for i in range(n-2,-1,-1):
            if arr[i]>rmax[i+1]:
                rmax[i]=arr[i]
            else:
                rmax[i]=rmax[i+1]
        
        # print(rmax)
        
        s=0
        
        for i in range(n):
            s+=(min(lmax[i],rmax[i])-arr[i])
        
        return s


#{ 
 # Driver Code Starts
#Initial template for Python 3

import math


def main():
    t = int(input())
    while (t > 0):

        arr = [int(x) for x in input().strip().split()]
        obj = Solution()
        print(obj.maxWater(arr))

        t -= 1
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends