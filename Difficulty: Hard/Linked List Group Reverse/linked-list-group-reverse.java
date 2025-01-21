//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int key) {
        data = key;
        next = null;
    }
}

class ReverseInSize {
    static Node head;

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        int t = Integer.parseInt(in.readLine().trim());

        while (t-- > 0) {

            String s[] = in.readLine().trim().split(" ");
            int a1 = Integer.parseInt(s[0]);
            Node head = new Node(a1);
            Node tail = head;
            for (int i = 1; i < s.length; i++) {
                int a = Integer.parseInt(s[i]);
                // addToTheLast(new Node(a));
                tail.next = new Node(a);
                tail = tail.next;
            }

            int k = Integer.parseInt(in.readLine().trim());
            Solution ob = new Solution();
            Node res = ob.reverseKGroup(head, k);
            printList(res, out);
            out.println();

            out.println("~");
        }
        out.close();
    }

    public static void printList(Node node, PrintWriter out) {
        while (node != null) {
            out.print(node.data + " ");
            node = node.next;
        }
    }
}

// } Driver Code Ends


/*node class of the linked list
class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}

*/

class Solution {
    public static Node reverseKGroup(Node head, int k) {
        // code here\
               if(k == 1) return head;
        
        Node curr = head, pre = null;
        
        for(int i = 0; i < k && curr != null; i++){
            Node nxt = curr.next;
            curr.next = pre;
            pre = curr;
            curr = nxt;
        }
        Node start = head;
        head = pre;
        int cnt = 0;
        if(curr == null) return head;
        pre = null;
        Node newSt = curr;
        
        while(curr != null){
            if(cnt < k){
                cnt++;
                Node nxt = curr.next;
                curr.next = pre;
                pre = curr;
                curr = nxt;
            }else{
                start.next = pre;
                start = newSt;
                newSt = curr;
                cnt = 0;
                pre = null;
            }
        }
        
        start.next = pre;
        return head;
    }
}
