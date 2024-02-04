//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
  Node* remove_trail(Node* head){
      Node* curr = head;Node* prev = NULL;
      while(curr != NULL && curr->data == 0){
          prev = curr;
          curr = curr->next;
      }
      
      if(prev){
      prev->next = NULL;
      }
      
      return curr;
  }
  
  pair<Node*,int> reverse(Node* head){
      Node* curr = head;Node* prev = NULL;
      int cnt = 0;
      
      while(curr != NULL){
          Node* forward = curr->next;
          curr->next = prev;
          prev=curr;
          curr = forward;
          cnt += 1;
      }
      
      return {prev,cnt};
  }
  
  bool isGreater(Node* head1,Node* head2){
      while(head1!=NULL && head2!=NULL){
          if(head1->data > head2->data){
              return true;
          }
          else if(head1->data < head2->data){
              return false;
          }
          
          head1 = head1->next;
          head2 = head2->next;
      }
  }
  
  Node* solve(Node* head1,Node* head2){
      
    //  cout<<head1->data<<endl;
      
      Node* ans = NULL;
      Node* ans_head = NULL;
      
      int extra = 0;
      while(head1 != NULL && head2 != NULL){
          int node = 0;
          if(head1->data-extra < head2->data){
              
              node =  head1->data + 10 - head2->data - extra;
              extra = 1;
          }
          else{
              node = head1->data - head2->data - extra;
              extra = 0;
          }
          
          //cout<<node<<endl;
          
          if(ans == NULL){
              ans = new Node(node);
              ans_head = ans;
          }
          else{
              ans->next = new Node(node);
              ans = ans->next;
          }
          
          head1 = head1->next;
          head2 = head2->next;
      }
      
      while(head1 != NULL){
          int node = 0;//head1->data-extra;
          
          if(head1->data-extra < 0){
              node = head1->data+10-extra;
              extra=1;
          }
          else{
              node = head1->data-extra;
              extra=0;
          }
          
        //   extra=0;
          
          if(ans == NULL){
              ans = new Node(node);
              ans_head = ans;
          }
          else{
              ans->next = new Node(node);
              ans = ans->next;
          }
          
          head1 = head1->next;
          
      }
      
      ans_head = reverse(ans_head).first;
      
      ans_head = remove_trail(ans_head);
      
      
      if(ans_head == NULL){
          return new Node(0);
      }
      return ans_head;
  }
  
public:
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        
        head1 = remove_trail(head1);head2 = remove_trail(head2);

        
        pair<Node*,int> p1 = reverse(head1);
        head1 = p1.first;int len1 = p1.second;
        
        pair<Node*,int> p2 = reverse(head2);
        head2 = p2.first;int len2 = p2.second;
        
         Node* ans = NULL;
        
        if(len1 > len2){
            ans = solve(head1,head2);
        }
        else if(len1 < len2){
            ans = solve(head2,head1);
        }
        else if(len1 == len2){
            p1 = reverse(head1);
            head1 = p1.first;len1 = p1.second;
        
            p2 = reverse(head2);
            head2 = p2.first;len2 = p2.second;
            
            bool chk = isGreater(head1,head2);
            
            p1 = reverse(head1);
            head1 = p1.first;len1 = p1.second;
        
            p2 = reverse(head2);
            head2 = p2.first;len2 = p2.second;
            
            if(chk){
                ans = solve(head1,head2); 
            }
            else{
                 ans = solve(head2,head1);
            }
        }
        
        return ans;
        
        
    }
};



//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends