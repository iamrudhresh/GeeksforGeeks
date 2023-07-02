#User function Template for python3

class Solution:
    def isdivisible7(self, num):
        # code here
        ans=int(num)
        if(ans%7==0):
            return 1
        else:
            return 0


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        s = input().strip()
        ob=Solution()
        print(ob.isdivisible7(s))
# } Driver Code Ends