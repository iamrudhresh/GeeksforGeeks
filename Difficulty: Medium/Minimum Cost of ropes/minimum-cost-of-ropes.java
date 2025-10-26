class Solution {
    public static int minCost(int[] arr) {
        // code here
        int n = arr.length;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int num : arr)
        {
            pq.add(num);
        }
        
        int minCost = 0;
        while(pq.size() > 1)
        {
            int n1 = pq.poll();
            int n2 = pq.poll();
            minCost += (n1 + n2);
            pq.add(n1 + n2);
        }
        
        return minCost;
    }
}

