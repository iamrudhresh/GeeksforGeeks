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
    /* Function to print nodes in a given linked list */
    static void printList(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    // Driver program to test the above functions
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = Integer.parseInt(scanner.nextLine());

        while (t-- > 0) {
            int n = Integer.parseInt(scanner.nextLine());
            List<Node> lists = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                String line = scanner.nextLine();
                String[] values = line.split(" ");
                Node head = null, temp = null;

                for (String value : values) {
                    Node newNode = new Node(Integer.parseInt(value));
                    if (head == null) {
                        head = newNode;
                        temp = head;
                    } else {
                        temp.next = newNode;
                        temp = temp.next;
                    }
                }

                lists.add(head);
            }

            Solution sol = new Solution();
            Node head = sol.mergeKLists(lists);

            printList(head);
            System.out.println("~");
        }
        scanner.close();
    }
}

// } Driver Code Ends


// User function Template for Java
/*class Node
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

// arr is an array of Nodes of the heads of linked lists

class Solution {
    // Function to merge K sorted linked list.
    Node mergeKLists(List<Node> arr) {
        // Add your code here.
           // Priority queue to store the nodes, sorting based on data values
        PriorityQueue<Node> minHeap = new PriorityQueue<>((a, b) -> a.data - b.data);
        
        // Add all the heads of linked lists into the minHeap
        for (Node head : arr) {
            if (head != null) {
                minHeap.add(head);
            }
        }
        
        // Dummy node to help construct the merged linked list
        Node dummy = new Node(0);
        Node tail = dummy;
        
        // Process the heap until it is empty
        while (!minHeap.isEmpty()) {
            // Extract the minimum node
            Node minNode = minHeap.poll();
            tail.next = minNode;  // Append it to the merged list
            tail = tail.next;  // Move the tail
            
            // If the extracted node has a next node, push it into the heap
            if (minNode.next != null) {
                minHeap.add(minNode.next);
            }
        }
        
        // Return the head of the merged list
        return dummy.next;
    }
}