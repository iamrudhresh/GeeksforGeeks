class Solution:
    def missingNum(self, arr):
        n=len(arr)
        ans=n+1
        for i in range(n):
            ans^=(arr[i]^(i+1))
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

t = int(input())
for _ in range(0, t):
    arr = list(map(int, input().split()))
    s = Solution().missingNum(arr)
    print(s)

    print("~")
# } Driver Code Ends