/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
    
    pair<int,int> solve(Node* root){
        if(root == NULL)return {0,0};
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        int val;
        if(left.second > right.second){
            return {left.first+root->data,left.second+1};
        }else if (left.second < right.second){
            return {right.first+root->data,right.second+1};
        }else {
            return {max(right.first,left.first)+root->data,right.second+1};
        }
    }
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        pair<int,int> ans = solve(root);
        return ans.first;
    }
};