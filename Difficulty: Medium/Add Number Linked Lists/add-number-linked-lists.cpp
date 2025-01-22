//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
   Node* reverse(Node*head){
      Node*prev=NULL;
      Node*next;
      Node*curr=head;
      while(curr!=NULL){
          next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=next;
      }
      return prev;
  }
    Node* addTwoLists(Node* num1, Node* num2) {
        while(num1->data==0){
            num1=num1->next;
        }
         while(num2->data==0){
            num2=num2->next;
        }
        
        Node*n1=reverse(num1);
        Node*n2=reverse(num2);
        Node*temp=new Node(-1);
        Node*sum=temp;
        int carry=0;
        while(n1!=NULL&&n2!=NULL){
            int a=n1->data;
            int b=n2->data;
            int digit=a+b+carry;
            carry=digit/10;
           int value=digit%10;
            Node*newNode=new Node(value);
            temp->next=newNode;
            temp=newNode;
            n1=n1->next;
            n2=n2->next;
        }
        while(n1!=NULL){
            int a=n1->data;
            int digit=a+carry;
             carry=digit/10;
          int  value=digit%10;
           
             Node*newNode=new Node(value);  
               temp->next=newNode;
               temp=newNode;
            
            n1=n1->next;
        }
            
        
        while(n2!=NULL){
            int b=n2->data;
            int digit=b+carry;
             carry=digit/10;
           int value=digit%10;
           
             Node*newNode=new Node(value);  
             temp->next=newNode;
            temp=newNode;
            n2=n2->next;
           
            
        }
        while(carry!=0){
            int digit=carry%10;
            if(digit==0){
                break;
            }
            carry=carry/10;
            Node*newNode=new Node(digit);
            temp->next=newNode;
            temp=newNode;
        }
        Node*ans=reverse(sum->next);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends