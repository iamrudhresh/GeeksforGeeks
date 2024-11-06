//{ Driver Code Starts
// Contributed by Sudarshan Sharma
import java.io.*;
import java.util.*;
import java.util.LinkedList;
import java.util.Queue;

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class GfG {

    static Node buildTree(String str) {

        if (str.length() == 0 || str.charAt(0) == 'N') {
            return null;
        }

        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue

        Queue<Node> queue = new LinkedList<>();

        queue.add(root);
        // Starting from the second element

        int i = 1;
        while (queue.size() > 0 && i < ip.length) {

            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();

            // Get the current node's value from the string
            String currVal = ip[i];

            // If the left child is not null
            if (!currVal.equals("N")) {

                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }

            // For the right child
            i++;
            if (i >= ip.length) break;

            currVal = ip[i];

            // If the right child is not null
            if (!currVal.equals("N")) {

                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));

                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }

        return root;
    }

    static void printInorder(Node root) {
        if (root == null) return;

        printInorder(root.left);
        System.out.print(root.data + " ");

        printInorder(root.right);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String s = br.readLine();
            Node root = buildTree(s);
            Solution ob = new Solution();
            System.out.println(ob.treePathsSum(root));
            // System.out.println();

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


/*Complete the function below.
Node is as follows:
class Tree
{
      int data;
      Tree left,right;
      Tree(int d){
          data=d;
          left=null;
          right=null;
}
}*/
class Solution {
    public static int treePathsSum(Node root) {
        // add code here.
        Stack<Pair> stack=new Stack<>();
        
        int sum=0;
        
         Pair pair;
         
         if(root==null)
         {
             return sum;
         }
         
         Node node=root;
         
         pair=new Pair(node,node.data);
         
         stack.push(pair);
         
         while(!stack.isEmpty())
         {
             int size=stack.size();
           
             for(int i=0;i<size;i++)
             {
                  
                  pair=stack.pop();
                
                 
                 if(pair.node.left==null && pair.node.right==null)
                 {
                     sum+=pair.val;
                 }
                 
                 if(pair.node.left!=null)
                 {
                     int data=( (pair.val)*10)+ pair.node.left.data;
                     stack.push(new Pair(pair.node.left,data));
                 }
                 
                 if(pair.node.right!=null)
                 {
                     int data=( (pair.val)*10)+pair.node.right.data;
                     stack.push(new Pair(pair.node.right,data));
                 }
             }
         }
         
         
         return sum;
    }
    
    
}


class Pair
{
     Node node;
     
     int val;
     
     
     public Pair(Node node, int val)
     {
         this.node=node;
         this.val=val;
        
    }
}