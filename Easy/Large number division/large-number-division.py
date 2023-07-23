#User function Template for python3

class Solution:
    def longDivision(self, S, D):
        # code here
        return int(S)//int(D)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        s = input().strip()
        d = int(input().strip())
        
        ob=Solution()
        print(ob.longDivision(s, d))
# } Driver Code Ends