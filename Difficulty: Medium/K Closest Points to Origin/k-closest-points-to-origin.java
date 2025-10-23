class Solution {
    public ArrayList<ArrayList<Integer>> kClosest(int[][] points, int k) {
        // code here
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            int x = (a[0] * a[0]) + (a[1] * a[1]);
            int y = (b[0] * b[0]) + (b[1] * b[1]);
            
            return Integer.compare(y, x);
        });
        
        for(int i = 0; i < points.length; i++) {
            if(pq.size() < k) {
                pq.offer(points[i]);
            }
            else {
                int[] a = pq.peek();
                int[] b = points[i];
                int x = (a[0] * a[0]) + (a[1] * a[1]);
                int y = (b[0] * b[0]) + (b[1] * b[1]);
                
                if(y < x) {
                    pq.poll();
                    pq.offer(b);
                }
            }
        }
        
        while(!pq.isEmpty()) {
            ArrayList<Integer> temp = new ArrayList<>();
            int[] poll = pq.poll();
            temp.add(poll[0]);
            temp.add(poll[1]);
            
            ans.add(temp);
        }
        
        return ans;
    }
}