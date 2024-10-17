//{ Driver Code Starts
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}

public class Main {
    public static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while (t-- > 0) {
            List<Integer> arr = new ArrayList<>();
            String input = sc.nextLine();
            Scanner ss = new Scanner(input);

            while (ss.hasNextInt()) {
                arr.add(ss.nextInt());
            }

            Node head = new Node(arr.get(0));
            Node tail = head;

            for (int i = 1; i < arr.size(); ++i) {
                tail.next = new Node(arr.get(i));
                tail = tail.next;
            }

            Solution ob = new Solution();
            Node[] result = ob.alternatingSplitList(head);
            printList(result[0]);
            printList(result[1]);
        }

        sc.close();
    }
}

// } Driver Code Ends


// User function Template for Java
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
    // Function to append a new node with newData at the end of a linked list
    Node[] alternatingSplitList(Node head) {
         Node first=head;
        Node second=head.next;
        Node f=first;
        Node s=second;
        if(head.next==null)
        return new Node[]{f,s};
        if(head.next.next==null){
            f.next=null;
            return new Node[]{f,s};
        }
        int flag=1;
        while(head.next!=null){
            if(flag==1){
                if(first.next.next==null){
                first.next=null;
                return new Node[]{f,s};
                }
                else
                first.next=first.next.next;
                flag=0;
                if(first.next!=null)
                first=first.next;
                head=head.next;
            }
            else if(flag==0){
                if(second.next.next==null){
                second.next=null;
                return new Node[]{f,s};
                }
                else
                 second.next=second.next.next;
                flag=1;
                if(second.next!=null)
                second=second.next;
                head=head.next;
            }
        }
        first.next=null;
        second.next=null;
        return new Node[] {f,s};
    }
}
