class Solution:
    def pushZerosToEnd(self, arr):
   # just keep an index i to keep track of  non-zeros
   # As it need to be done inplace change the arr itself
   # when you find a non-zero then replace the element at index i with that
        i=0
        for x in arr:
           if x!=0:
              arr[i]=x
              i+=1
       # now after completing all postives now arr should be filled with zeros
       # index i will be at last positive number in the arr ,from there till len(arr)-1[zero based indexing] fill zeros
        while i<len(arr):
            arr[i]=0
            i+=1
        return arr
