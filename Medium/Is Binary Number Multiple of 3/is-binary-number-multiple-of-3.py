#User function Template for python3
class Solution:
	def isDivisible(self, s):
	    n = int(s,2)
        return 1 if n%3==0 else 0
		# code here


#{ 
 # Driver Code Starts

#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		s = input()
		ob = Solution()
		ans = ob.isDivisible(s)
		print(ans)

# } Driver Code Ends