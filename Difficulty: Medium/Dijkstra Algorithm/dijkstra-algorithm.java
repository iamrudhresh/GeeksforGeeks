//{ Driver Code Starts
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = Integer.parseInt(sc.nextLine());

        while (t-- > 0) {
            int V = Integer.parseInt(sc.nextLine());
            int E = Integer.parseInt(sc.nextLine());

            List<int[]> edgeList = new ArrayList<>();

            for (int i = 0; i < E; i++) {
                String[] parts = sc.nextLine().split(" ");
                int u = Integer.parseInt(parts[0]);
                int v = Integer.parseInt(parts[1]);
                int w = Integer.parseInt(parts[2]);
                edgeList.add(new int[] {u, v, w});
                edgeList.add(new int[] {v, u, w});
            }

            int[][] edges = new int[edgeList.size()][3];
            for (int i = 0; i < edgeList.size(); i++) {
                edges[i] = edgeList.get(i);
            }

            int src = Integer.parseInt(sc.nextLine());

            Solution obj = new Solution();
            int[] res = obj.dijkstra(V, edges, src);

            for (int val : res) {
                System.out.print(val + " ");
            }
            System.out.println();
            System.out.println("~");
        }

        sc.close();
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {
    public int[] dijkstra(int V, int[][] edges, int src) {
        // code here
          List<List<int[]>> adj = new ArrayList<>();
        
        for(int i=0;i<V;i++)
            adj.add(new ArrayList<>());
        
        for(int[] edge: edges){
            
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj.get(u).add(new int[]{u,w});
            adj.get(v).add(new int[]{u,w});
        }
        
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)-> a[1]-b[1]);
        pq.add(new int[]{src,0});
        
        while(!pq.isEmpty()){
            
            int [] curr = pq.poll();
            int u = curr[0];
            int d = curr[1];
            
            if(d>dist[u]) continue;
            
            for(int[] neighbor : adj.get(u)){
                int v = neighbor[0];
                int w = neighbor[1];
                
                if(dist[u]+w<dist[v]){
                    dist[v]= dist[u]+w;
                    pq.add(new int[]{v,dist[v]});
                }
            }
        }
        return dist;
    }
}