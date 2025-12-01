class Solution {
    private static final int MAX_BIT = 16;

    private static class Node {
        Node[] next = new Node[2];
        int count = 0; 
    }

    private final Node root = new Node();

   
    private void insert(int num) {
        Node cur = root;
        for (int i = MAX_BIT - 1; i >= 0; --i) {
            int b = (num >> i) & 1;
            if (cur.next[b] == null) cur.next[b] = new Node();
            cur = cur.next[b];
            cur.count++;
        }
    }

   
    private long countLessThanK(int num, int k) {
        Node cur = root;
        long cnt = 0;
        for (int i = MAX_BIT - 1; i >= 0; --i) {
            if (cur == null) break;
            int nb = (num >> i) & 1;
            int kb = (k >> i) & 1;

            if (kb == 1) {
                
                Node same = cur.next[nb];
                if (same != null) cnt += same.count;
               
                cur = cur.next[1 - nb];
            } else {
            
                cur = cur.next[nb];
            }
        }
        return cnt;
    }

    public int cntPairs(int[] arr, int k) {
        long ans = 0;
       
        for (int x : arr) {
            ans += countLessThanK(x, k);
            insert(x);
        }
        return (int) ans; 
    }
}

