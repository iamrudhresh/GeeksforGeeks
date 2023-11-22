//{ Driver Code Starts
import java.io.*;
import java.util.*;

class pair
{
    int first;
    boolean second;
    pair(int first, boolean second)
        {
            this.first = first;
            this.second = second;
        }
}
class Node
{
    int data, height;
    Node left, right;
    
    Node(int x)
    {
        data=x;
        left=right=null;
        height=1;
    }
}
class GfG
{
    public static boolean isBST(Node n, int lower, int upper)
    {
    	if(n==null) return true;
    	if( n.data <= lower || n.data >= upper ) return false;
    	return isBST(n.left, lower, n.data) && isBST(n.right, n.data, upper) ;
    }
    
    public static pair isBalanced(Node n)
    {
    	if(n==null)
    	    {
    	        return new pair(0,true);
    	    }
        
    	pair l = isBalanced(n.left);
    	pair r = isBalanced(n.right);
    
    	if( Math.abs(l.first - r.first) > 1 ) return new pair (0,false);
    
    	return new pair( 1 + Math.max(l.first , r.first) , l.second && r.second );
    }
    
    public static boolean isBalancedBST(Node root)
    {
    	if( isBST(root, Integer.MIN_VALUE , Integer.MAX_VALUE) == false )
    		System.out.print("BST voilated, inorder traversal : ");
    
    	else if ( isBalanced(root).second == false)
    		System.out.print("Unbalanced BST, inorder traversal : ");
    
    	else return true;
    	return false;
    }
    
    public static void printInorder(Node n)
    {
    	if(n==null) return;
    	printInorder(n.left);
    	System.out.print(n.data + " ");
    	printInorder(n.right);
    }


    public static void main(String args[])
        {
            int ip[] = new int[2000];
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    for(int i = 0; i < n; i++)
                        {
                            ip[i] = sc.nextInt();
                        }
                        
                    Node root = null;
                    Solution obj = new Solution();
                    for(int i=0; i<n; i++)
                    {
                        root = obj.insertToAVL( root, ip[i] );
                        
                        if ( isBalancedBST(root) == false )
                            break;
                    }
                    
                    printInorder(root);
                    System.out.println();
                    
                }
            
                
        }
}
// } Driver Code Ends


//User function Template for Java

/*
class Node
{
    int data;
    Node left;
    Node right;
    int height;
};
*/
class Solution {
    public Node insertToAVL(Node node, int data) {
        if (node == null) {
            return new Node(data);
        }
        if (node.data > data) {
            node.left = insertToAVL(node.left, data);
        } else if (node.data < data) {
            node.right = insertToAVL(node.right, data);
        }
        node.height = Math.max(height(node.left), height(node.right)) + 1;
        int diff = height(node.left) - height(node.right);
        if (diff > 1) { // Left subtree is higher
            if (data < node.left.data) {
                return rightRotate(node);
            } else if (data > node.left.data) { // LR rotation
                node.left = leftRotate(node.left);
                return rightRotate(node);
            }
        } else if (diff < -1) { // Right subtree is higher
            if (data < node.right.data) { // RL rotation
                node.right = rightRotate(node.right);
                return leftRotate(node);
            } else if (data > node.right.data) {
                return leftRotate(node);
            }
        }
        return node;
    }

    public Node leftRotate(Node a) {
        Node b = a.right;
        Node t2 = b.left;
        b.left = a;
        a.right = t2;
        a.height = Math.max(height(a.left), height(a.right)) + 1;
        b.height = Math.max(height(b.left), height(b.right)) + 1;
        return b;
    }

    public Node rightRotate(Node a) {
        Node b = a.left;
        Node t2 = b.right;
        b.right = a;
        a.left = t2;
        a.height = Math.max(height(a.left), height(a.right)) + 1;
        b.height = Math.max(height(b.left), height(b.right)) + 1;
        return b;
    }

    public int height(Node node) {
        if (node == null) {
            return 0;
        } else {
            return node.height;
        }
    }
}