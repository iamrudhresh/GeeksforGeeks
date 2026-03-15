from collections import defaultdict, deque

class Solution:
    def verticalOrder(self, root): 
        if not root:
            return []
            
        hashmap = defaultdict(list)
        queue = deque([(root, 0)])
        
        while queue:
            node, level = queue.popleft()
            
            hashmap[level].append(node.data)
            
            if node.left:
                queue.append((node.left, level-1))
            if node.right:
                queue.append((node.right, level+1))
        
        res = [val for _, val in sorted(hashmap.items())]        
        return res

