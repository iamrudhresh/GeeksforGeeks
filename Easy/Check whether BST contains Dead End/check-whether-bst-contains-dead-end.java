//{ Driver Code Starts

import java.util.*;
import java.io.*;
class Node {
        int data;
        Node left, right;
 
        Node(int item) {
            data = item;
            left = right = null;
        }
    }
class BinarySearchTree {
    public static Node root;
    BinarySearchTree() { 
        root = null; 
    }
    void insert(int key) {
       root = insertRec(root, key);
    }
    Node insertRec(Node root, int key) {
        if (root == null) {
            root = new Node(key);
            return root;
        }
        if (key < root.data)
            root.left = insertRec(root.left, key);
        else if (key > root.data)
            root.right = insertRec(root.right, key);
        return root;
    }
 
    public static void inorder()  {
       inorderRec(root);
    }
    public static void inorderRec(Node root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.print(root.data);
            inorderRec(root.right);
        }
    }
 
    // Driver Program to test above functions
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0)
        {
            int n=sc.nextInt();
            int []a=new int[n];
            BinarySearchTree obj1=new BinarySearchTree();
            for(int i=0;i<n;i++)
            {
                int b=sc.nextInt();
                obj1.insert(b);
            }
            //inorder();
            Solution obj=new Solution();
            boolean k=obj.isDeadEnd(root);
            if(k==true)
            System.out.println("1");
            else
            System.out.println("0");
        }       
    }
}


// } Driver Code Ends


/*class Node {
        int data;
        Node left, right;
 
        Node(int item) {
            data = item;
            left = right = null;
        }
    }*/

//Function should return true if a deadEnd is found in the bst otherwise return false.
class Solution
{
    public static boolean isDeadEnd(Node root)
    {
        // HashSet<Integer> allNodes = new HashSet<>();
        // HashSet<Integer> leafNodes = new HashSet<>();
        
        // allNodes.add(0);
        
        // storeNodes(root, allNodes, leafNodes);
        
        // for(int i : leafNodes){
        //     int x = i;
        //     if(allNodes.contains(x+1) && allNodes.contains(x-1)){
        //         return true;
        //     }
        // }
        // return false;
        
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0,1);
        findAllNodes(root, map);
        return check(root, map);
    }
    // public static void storeNodes(Node root, HashSet<Integer> allNodes, HashSet<Integer> leafNodes){
    //     if(root == null){
    //         return;
    //     }
    //     allNodes.add(root.data);
        
    //     if(root.left == null && root.right == null){
    //         leafNodes.add(root.data);
    //         return;
    //     }
    //     storeNodes(root.left, allNodes, leafNodes);
    //     storeNodes(root.right, allNodes, leafNodes);
    // }
    
    public static void findAllNodes(Node root, Map<Integer, Integer> map){
        if(root == null)return;
        
        map.put(root.data, 1);
        findAllNodes(root.left, map);
        findAllNodes(root.right, map);
    }
    public static boolean check(Node root, Map<Integer, Integer> map){
        if(root == null)return false;
        
        if(root.left == null && root.right == null){
            int pre = root.data-1;
            int nex = root.data+1;
            
            if(map.containsKey(pre) && map.containsKey(nex)){
                return true;
            }
        }
        return check(root.left, map) || check(root.right, map);
    }
}

