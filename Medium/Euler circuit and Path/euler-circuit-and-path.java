//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class GFG {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int tc = scanner.nextInt();
        
        while (tc-- > 0) {
            int V = scanner.nextInt();
            int E = scanner.nextInt();
            
            List<Integer>[] adj = new ArrayList[V];
            for (int i = 0; i < V; i++) {
                adj[i] = new ArrayList<>();
            }
            
            for (int i = 0; i < E; i++) {
                int u = scanner.nextInt();
                int v = scanner.nextInt();
                adj[u].add(v);
                adj[v].add(u);
            }
            
            // String x=scanner.nextLine();
            // scanner.nextLine();
            
            Solution obj = new Solution();
            int ans = obj.isEulerCircuit(V, adj);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends



class Solution{
    public int isEulerCircuit(int V, List<Integer>[] adj) 
    {
        // code here
         int odd=0, ev = 0;
        // counting degree of all nodes, odd and even degree nodes
        for(int i=0; i<V; i++){
            if( adj[i].size() % 2 == 0 ) ev++;
            else odd++;
        }
        
        // for undirected graph
        // euler circuit must have all node with even degree
        // euler circuit must have all even degree node with atmost 2 odd degree nodes
        if( ev == V ) return 2;
        else if( odd > 0 && odd==2 ) return 1;
        return 0;
    }
}
