import heapq
class Solution:
     def kthLargest(self, arr, k):
          n = len(arr)
          
          heap = []
          ans = []
          h_i = 0

          for i in range(n):
               heapq.heappush(heap, arr[i])
               h_l = len(heap)

               if h_l < k:
                    ans.append(-1)
               elif h_l == k:
                    ans.append(heap[0])
               elif h_l > k:
                    heapq.heappop(heap)
                    ans.append(heap[0])
          return ans