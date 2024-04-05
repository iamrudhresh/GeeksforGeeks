#User function Template for python3

class Solution:
    def splitString(ob, S): 
        # code here 
        s1=""
        s2=""
        s3=""
        for i in S:
            if i.isalpha():
                s1+=i
            elif i.isdigit():
                s2+=i
            else:
                s3+=i
        return [s1,s2,s3]
       


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        S = input()
        ob = Solution()
        ans = ob.splitString(S)
        for i in ans:
            if(i==""):
                print(-1)
            else:
                print(i)


# } Driver Code Ends