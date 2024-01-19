#User function Template for python3

class Solution:
    def min_sprinklers(self, gallery, n):
        sprinklers = []

        for i in range(n):
            if gallery[i] != -1:
                sprinklers.append((i - gallery[i], i + gallery[i]))

        sprinklers.sort()
        m = len(sprinklers)
        target, i, ans = 0, 0, 0

        while target < n and i < m:
            if sprinklers[i][0] > target:
                return -1

            maxi = sprinklers[i][1]
            i += 1

            while i < m and sprinklers[i][0] <= target:
                maxi = max(maxi, sprinklers[i][1])
                i += 1

            target = maxi + 1
            ans += 1

        if target < n - 1:
            return -1
        else:
            return ans






#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        gallery = [int(x) for x in input().strip().split()]
        obj = Solution()
        print(obj.min_sprinklers(gallery,n))

# } Driver Code Ends