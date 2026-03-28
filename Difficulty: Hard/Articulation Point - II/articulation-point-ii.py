class Solution:
    def articulationPoints(self, V, edges):
        def dfs (node, parent):
            vis[node] = 1
            tin[node] = low[node] = timer[0]
            timer[0] += 1
            child = 0
            
            for it in adj[node]:
                if it == parent:
                    continue
                
                if not vis[it]:
                    dfs(it, node)
                    
                    low[node] = min(low[node], low[it])
                    
                    if low[it] >= tin[node] and parent != -1:
                        mark[node] = 1
                        
                    child += 1
                    
                else:
                    low[node] = min(low[node], tin[it])
                    
            if parent == -1 and child > 1:
                mark[node] = 1
                
        
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            
        vis = [0] * V
        tin = [0] * V
        low = [0] * V
        mark = [0] * V
        timer = [0]
        
        for i in range(V):
            if not vis[i]:
                dfs(i, -1)
                
        ans = []
        for i in range(V):
            if mark[i] == 1:
                ans .append(i)
                
        if len(ans) == 0:
            return [-1]
            
        return ans