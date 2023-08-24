#User function Template for python3

class Solution:
    def multiplyStrings(self,s1,s2):
        x1=int(s1)
        x2=int(s2)
        return x1*x2
        # code here
        # return the product string
        return 





#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t=int(input())
    for i in range(t):
        a,b=input().split()
        print(Solution().multiplyStrings( a.strip() , b.strip() ))

# } Driver Code Ends