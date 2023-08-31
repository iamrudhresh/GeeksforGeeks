//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

int setHeights(Node* n)
{
	if(!n) return 0;
	n->height = 1 + max( setHeights(n->left) , setHeights(n->right) );
	return n->height;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    setHeights(root);
    return root;
}

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}

struct Node* deleteNode(struct Node* root, int data);

int main()
{
	int t;
	cin>>t;
	getchar();

	while(t--)
	{
		string s;
		getline(cin,s);
		Node* root = buildTree(s);
        
		int n;
		cin>> n;
		int ip[n];
		for(int i=0; i<n; i++)
			cin>> ip[i];
        
		for(int i=0; i<n; i++)
		{
			root = deleteNode(root, ip[i]);
			
			if( !isBalancedBST(root) )
				break;
		}
        
		if(root==NULL)
			cout<<"null";
		else
			printInorder(root);
		cout<< endl;
        
		getline(cin,s); // to deal with newline char
	}
	return 1;
}

// } Driver Code Ends


/* Node is as follows:

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

*/

Node *left(Node *root){ // left rotation
    Node *tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    return tmp;
}

Node *right(Node *root){ // right rotation
    Node *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    return tmp;
}

Node *RL(Node *root){ // right left Rotation
    root->right = right(root->right);
    return left(root);
}

Node *LR(Node *root){ // left right Rotation
    root->left = left(root->left);
    return right(root);
}

Node* Minimum(Node *root){
    if(!root) return root;
    if(!root->left) return root->right;
    root->left = Minimum(root->left);
    return root; 
}

Node* Maximum(Node *root){
    if(!root) return root;
    if(!root->right) return root->left;
    root->right = Maximum(root->right); 
    return root;
}

int height(Node *root){  // for height of the AVL tree
    if(!root) return 0;
    return 1+max(height(root->left),height(root->right));
}

Node *check(Node *root){
    if(!root) return root;
    root->left = check(root->left);
    root->right = check(root->right);
    int a = height(root->left);
    int b = height(root->right);
    if(a-b > 1 or a-b < -1){
        if(a>b){ // problem in Left subTree
            if(height(root->left->left)<height(root->left->right)) root = LR(root);
            else root = right(root);
        }
        else{ // problem in Right subTree
            if(height(root->right->left)>height(root->right->right)) root = RL(root);
            else root = left(root);
        }
    }
    root->height = max(height(root->left),height(root->right))+1; // updating height
    return root;
}

Node* deleteNode(Node* root, int data)
{
    if(!root) return root;
    if(root->data == data){
        if(!root->left and !root->right) return root->left;
        else if(!root->left){
            Node *ptr = root->right;
            while(ptr->left) ptr=ptr->left;
            root->data = ptr->data;
            root->right = Minimum(root->right);
        }
        else{
            Node *ptr = root->left;
            while(ptr->right) ptr=ptr->right;
            root->data = ptr->data;
            root->left = Maximum(root->left);
        }
    }
    else if(data < root->data) root->left = deleteNode(root->left,data);
    else root->right = deleteNode(root->right,data);
    root = check(root);
    return root;
}