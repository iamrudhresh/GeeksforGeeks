from collections import deque
class Solution:
    
    def shortCycle(self, V, edges):
        adj=[[] for _ in range(V)]
        for u,v in edges:
            adj[u].append(v)
            adj[v].append(u)
        ans=float("inf")
        for start in range(V):
            dist=[-1]*V
            parent=[-1]*V
            q=deque([start])
            dist[start]=0
            while q:
                u=q.popleft()
                for v in adj[u]:
                    if dist[v]==-1:
                        q.append(v)
                        dist[v]=dist[u]+1
                        parent[v]=u
                    elif parent[u]!=v:
                        ans=min(ans,dist[v]+dist[u]+1)
        return ans if ans!=float("inf") else -1