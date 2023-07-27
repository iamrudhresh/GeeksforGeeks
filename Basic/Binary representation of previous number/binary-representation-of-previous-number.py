#User function Template for python3
class Solution:
	def binaryPreviousNumber(self, S):
		# code here
		x = int(S,2)
		return bin(x-1)[2:]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		S = input()
		ob = Solution()
		ans = ob.binaryPreviousNumber(S)
		print(ans)




# } Driver Code Ends