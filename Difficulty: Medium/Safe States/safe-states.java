class Solution {
    public ArrayList<Integer> safeNodes(int V, int[][] edges) {
        ArrayList<ArrayList<Integer>> revGraph = new ArrayList<>();
        int[] outdeg = new int[V];
        for (int i = 0; i < V; i++) 
            revGraph.add(new ArrayList<>());
        for (int[] e : edges) {
            int u = e[0], v = e[1];
            revGraph.get(v).add(u);
            outdeg[u]++;
        }
        Queue<Integer> q = new LinkedList<>();
        ArrayList<Integer> safe = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            if (outdeg[i] == 0){
                q.add(i);
            } 
        }
        while (!q.isEmpty()) {
            int node = q.poll();
            safe.add(node);
            
            for (int parent : revGraph.get(node)) {
                outdeg[parent]--;
                if (outdeg[parent] == 0){
                    q.add(parent);
                }
            }
        }
        Collections.sort(safe);
        return safe;
    }
}