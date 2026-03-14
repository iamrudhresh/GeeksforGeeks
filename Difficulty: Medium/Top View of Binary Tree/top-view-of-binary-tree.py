'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def topView(self, root):
        if root is None:
            return []
        
        from collections import deque
        
        q = deque()
        q.append((root, 0))   # node, horizontal distance
        
        mp = {}
        
        while q:
            node, hd = q.popleft()
            
            # store first node for each horizontal distance
            if hd not in mp:
                mp[hd] = node.data
            
            if node.left:
                q.append((node.left, hd - 1))
            
            if node.right:
                q.append((node.right, hd + 1))
        
        ans = []
        
        for key in sorted(mp):
            ans.append(mp[key])
        
        return ans
        
        