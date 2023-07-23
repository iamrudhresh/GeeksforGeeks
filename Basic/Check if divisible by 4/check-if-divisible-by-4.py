#User function Template for python3
class Solution:
	def divisibleBy4 (self, N):
		# Your Code Here
		num=int(N)
		
		if(num%4==0):
		    return 1
		else:
		    return 0

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
	t = int (input ())
	for tc in range (t):
		s = input ()
		ob = Solution()
		print(ob.divisibleBy4(s))

		#  Contributed By: Pranay Bansa
# } Driver Code Ends