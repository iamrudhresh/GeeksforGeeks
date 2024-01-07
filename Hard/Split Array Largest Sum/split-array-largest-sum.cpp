//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int maxi(int arr[],int n){
      int x=0;
      for(int i=0;i<n;i++)x=max(x,arr[i]);
      return x;
  }
  int sum(int arr[],int n){
      int x=0;
      for(int i=0;i<n;i++)x+=arr[i];
      return x;
  }
    int countStudents(int arr[], int pages,int n) {
       // int n = arr.size(); //size of array.
        int students = 1;
        long long pagesStudent = 0;
        for (int i = 0; i < n; i++) {
            if (pagesStudent + arr[i] <= pages) {
                //add pages to current student
                pagesStudent += arr[i];
            }
            else {
                //add pages to next student
                students++;
                pagesStudent = arr[i];
            }
        }
        return students;
}

int findPages(int arr[], int n, int m) {
    //book allocation impossible:
    if (m > n) return -1;

    int low = maxi(arr,n);
    int high = sum(arr,n);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid,n);
        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}
    int splitArray(int arr[] ,int N, int K) {
        return findPages(arr,N,K);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends