//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    bool isGreater(Node*curr)
    {
        Node *temp = curr->next;
        while(temp)
        {
            if(curr->data < temp->data)
            return true;
            else
            temp = temp->next;
        }
        return false;
    }
    void deleteNode(Node*&head, Node*&curr)
    {
        if(head==curr)
        {
            head = head->next;
            delete(curr);
            curr=head;
            return;
        }
        Node *temp = head;
        while(temp->next !=curr)
        {
            temp = temp->next;
        }
        temp->next = curr->next;
        delete(curr);
        curr = temp->next;
        
    }
    Node *compute(Node *head)
    {
        if(head==NULL||head->next==NULL)
        return head;
        
        Node*temp = head;
        
        while(temp)
        {
            if(temp->next != NULL && isGreater(temp))
            {
                deleteNode(head,temp);
            }
            else
            temp = temp->next;
            
        }
        return head;
    }
    
};


   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends