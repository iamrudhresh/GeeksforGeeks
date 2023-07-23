#User function Template for python3
class Solution:
	def divisibleBy11(self, S):
		# Your Code Here
		num=int(S)
		if(num%11==0):
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
		print (ob.divisibleBy11 (s)) 

# Contributed By: Pranay Bansal

# } Driver Code Ends