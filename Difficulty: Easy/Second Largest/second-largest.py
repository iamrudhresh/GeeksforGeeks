class Solution:
    def getSecondLargest(self, arr):
       
        s = set(arr)
        s = sorted(s)
        if len(s)<2:
            return -1
        return s[-2]