#User function Template for python3

class Solution:
    
    #Function to find the largest number after k swaps.
    def findMaximumNum(self, s, k):
        #code here
        s = list(s)
        n = len(s)
        for i in range(n):
            j = max([(s[j], j) for j in range(i, n)])[1]
            if s[i] != s[j]:
                s[i], s[j] = s[j], s[i]
                k -= 1
            if k == 0:
                break
        return ''.join(s)



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    for _ in range(int(input())):
        k = int(input())
        s = input()
        ob = Solution()
        print(ob.findMaximumNum(s, k))

        print("~")

# } Driver Code Ends