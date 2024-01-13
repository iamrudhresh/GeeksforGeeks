//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
class Node
    {
        int data;
        Node next;
        Node(int d) {data = d; next = null; }
    }
class insertion
{
    Node head;  
    Node tail;
	public void addToTheLast(Node node) 
	{
	  if (head == null) 
	  {
	   head = node;
	   tail = node;
	  } 
	  else 
	  {
	   tail.next = node;
	   tail = node;
	  }
	}
      void printList(Node head)
    {
        Node temp = head;
        while (temp != null)
        {
           System.out.print(temp.data+" ");
           temp = temp.next;
        }  
        System.out.println();
    }
	/* Drier program to test above functions */
	public static void main(String args[])
    {
         Scanner sc = new Scanner(System.in);
		 int t=sc.nextInt();
		 while(t>0)
         {
			int n = sc.nextInt();
			insertion llist = new insertion(); 
			int a1=sc.nextInt();
			Node head= new Node(a1);
            llist.addToTheLast(head);
            for (int i = 1; i < n; i++) 
			{
				int a = sc.nextInt(); 
				llist.addToTheLast(new Node(a));
			}
			
        Solution ob = new Solution();
		head = ob.insertionSort(llist.head);
		llist.printList(head);
		
        t--;		
        }
    }}
// } Driver Code Ends


//User function Template for Java

/*class Node
    {
        int data;
        Node next;
        Node(int d) {data = d; next = null; }
    }
    */
class Solution
{
       public static Node insertionSort(Node head){
        
        // head agar kahli ho ya fir head ka next khali ho toh return head 
        if(head == null || head.next == null){
            return head;
        }  
        
        // created a newNode and initialize with  -1
        Node newNode = new Node(-1);
        // created curr and initialize with head
        Node curr = head;
        
         // jab tak null nahi ho jata 
         while(curr != null){
        // created a nextnode and initialize with  curr.next
        Node nextNode = curr.next;
         // i think this is the iterator  to keep track in new node
        //  created a temp  and initialize with newNode
        Node temp = newNode; 

        // jab tak  temp null nahi ho jata hai or temp ka next ka jo data hai wo chot ho curr ka data se
        while(temp.next != null && temp.next.data <= curr.data ){
             // temp ka next temp ban jayega  age bad jayega 
              temp = temp.next;
        }
             //temp ka next curr ka next ban jayega 
             curr.next = temp.next;
             // curr ja ha tha wo ab temp.next ban jaega 
             temp.next = curr;
             // nextnode will point  curr
             curr = nextNode;
             
         }

//.next isilye because we have initialize it with -1 
         return newNode.next;
    }
}