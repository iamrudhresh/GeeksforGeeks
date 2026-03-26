import heapq
class Solution:
    def countPaths(self, V, edges):
        # Build adjacency list
        graph = [[] for _ in range(V)]
        for u, v, w in edges:
            graph[u].append((v, w))
            graph[v].append((u, w))  # undirected
        
        # Initialize
        dist = [float('inf')] * V
        ways = [0] * V
        dist[0] = 0
        ways[0] = 1
        
        # Min-heap for Dijkstra
        pq = [(0, 0)]  # (distance, node)
        
        while pq:
            d, u = heapq.heappop(pq)
            
            if d > dist[u]:
                continue
            
            for v, w in graph[u]:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    ways[v] = ways[u]
                    heapq.heappush(pq, (dist[v], v))
                elif dist[u] + w == dist[v]:
                    ways[v] += ways[u]
        
        return ways[V-1]  