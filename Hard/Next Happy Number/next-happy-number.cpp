//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool isHappy(int num) {
    unordered_set<int> visited;
    while (num != 1 && visited.find(num) == visited.end()) {
        visited.insert(num);
        int sum = 0;
        while (num > 0) {
            int digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        num = sum;
    }
    return num == 1;
}

    int nextHappy(int N){
        // code here
        int num = N + 1;
    while (!isHappy(num)) {
        num++;
    }
    return num;

    }
    
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends