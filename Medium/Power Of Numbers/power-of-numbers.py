#User function Template for python3

class Solution:
    #Complete this function
    def power(self,N,R):
        #Your code here
        if N==0:
            return 0
        if R==0:
            return 1
        temp=self.power(N, R//2)
        temp*=temp
        if R&1:
            return (temp*N)%1000000007
        else:
            return temp%1000000007


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

def main():
    
    T=int(input())
    
    while(T>0):
        
        N=input()
        R=N[::-1]
        
        ob=Solution();
        ans=ob.power(int(N),int(R))
        print(ans)
        
        T-=1

if __name__=="__main__":
    main()
# } Driver Code Ends