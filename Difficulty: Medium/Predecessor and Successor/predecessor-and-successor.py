'''
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
'''

class Solution:
    def findPreSuc(self, root, key):
        # code here
        self.predecessor = None
        self.successor = None
        self.key = key
        
        self._traverse(root)
        
        return self.predecessor, self.successor

    def _traverse(self, node):
        if node is None:
            return
        
        # Check if node.data < key and greater than current predecessor
        if node.data < self.key:
            if (self.predecessor is None) or (node.data > self.predecessor.data):
                self.predecessor = node
        
        # Check if node.data > key and less than current successor
        if node.data > self.key:
            if (self.successor is None) or (node.data < self.successor.data):
                self.successor = node
        
        self._traverse(node.left)
        self._traverse(node.right)


#{ 
 # Driver Code Starts
import queue


# BST Node
class Node:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def buildTree(ip):
    # Corner Case
    if len(ip) == 0 or ip[0] == 'N':
        return None

    # Create the root of the tree
    root = Node(int(ip[0]))

    # Push the root to the queue
    q = queue.Queue()
    q.put(root)

    # Starting from the second element
    i = 1
    while not q.empty() and i < len(ip):
        # Get and remove the front of the queue
        currNode = q.get()

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if currVal != "N":
            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            q.put(currNode.left)

        # For the right child
        i += 1
        if i >= len(ip):
            break
        currVal = ip[i]

        # If the right child is not null
        if currVal != "N":
            # Create the right child for the current node
            currNode.right = Node(int(currVal))

            # Push it to the queue
            q.put(currNode.right)

        i += 1

    return root


# Driver program to test above functions
t = int(input())
for _ in range(t):
    s = input()
    root = buildTree(s.split())
    key = int(input())

    ob = Solution()
    result = ob.findPreSuc(root, key)
    pre, suc = result[0], result[1]

    if pre is not None:
        print(pre.data, end=" ")
    else:
        print(-1, end=" ")

    if suc is not None:
        print(suc.data)
    else:
        print(-1)
    print("~")

# } Driver Code Ends