#User function Template for python3
class Solution:
    def checkDivisible36 (ob,S):
        # code here 
        num=int(S)
        if(num%36==0):
            return 1
        else:
            return 0


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        
        S=str(input())

        ob = Solution()
        print(ob.checkDivisible36(S))
# } Driver Code Ends