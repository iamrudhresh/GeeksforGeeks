//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  private:
    bool isPrime(int n){
        if(n<=1) return false;
        for(int i=2;i*i<=n;++i){
            if((n % i) == 0){
                return false;
            }
        }
        return true;
    }
    
    int prevPrime(int n){
        
        for(int i=n-1;i>=2;--i){
            if(isPrime(i)){
                return i;
            }
        }
        return -1;
    }
    
    int nextPrime(int n){
        
        for(int i=n+1;;i++){
            if(isPrime(i)){
                return i;
            }
        }
    }
    
    
  public:
    Node *primeList(Node *head) {
        Node* temp=head;
        while(temp){
            if(temp->val==1){
                temp->val=2;
            }else if(!isPrime(temp->val)){
                int nxt=nextPrime(temp->val);
                int prev=prevPrime(temp->val);
                if(temp->val - prev ==  nxt-temp->val){
                    temp->val = prev;
                }else if(temp->val-prev < nxt-temp->val){
                    temp->val=prev;
                }else{
                    temp->val=nxt;
                }
            }
            temp=temp->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends