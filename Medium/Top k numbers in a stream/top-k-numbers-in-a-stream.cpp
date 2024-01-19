//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution
{
  public:
    // Function to print top k numbers
    vector<vector<int>> kTop(vector<int>&a, int n, int k)
    {
        // vector of size k+1 to store elements
        vector<int> top(k + 1);
        vector<vector<int>> ans;
        // array to keep track of frequency
        unordered_map<int, int> freq;
        // iterate till the end of stream
        for (int m = 0; m < n; m++) {
            
            vector<int>temp;
            // increase the frequency
            freq[a[m]]++;
            // store that element in top vector
            top[k] = a[m];
            // search in top vector for same element
            auto it = find(top.begin(), top.end() - 1, a[m]);
            // iterate from the position of element to zero
            for (int i = distance(top.begin(), it) - 1; i >= 0; --i) {
                // compare the frequency and swap if higher
                // frequency element is stored next to it
                if (freq[top[i]] < freq[top[i + 1]])
                    swap(top[i], top[i + 1]);
                // if frequency is same compare the elements
                // and swap if next element is high
                else if ((freq[top[i]] == freq[top[i + 1]])
                         && (top[i] > top[i + 1]))
                    swap(top[i], top[i + 1]);
                else
                    break;
            }
            // print top k elements
            for (int i = 0; i < k && top[i] != 0; ++i)
                temp.push_back(top[i]);
                //cout << top[i] << ' ';
            ans.push_back(temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends