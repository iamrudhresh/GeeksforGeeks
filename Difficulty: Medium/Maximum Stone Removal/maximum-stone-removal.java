import java.util.*;

class Solution {
    public int maxRemove(int[][] stones) {
        int n = stones.length;
        
        // Extend stones with index: [x, y, idx]
        int[][] ext = new int[n][3];
        for (int i = 0; i < n; i++) {
            ext[i][0] = stones[i][0];
            ext[i][1] = stones[i][1];
            ext[i][2] = i;            // original index
        }

        // Adjacency list: node index -> neighbors
        Map<Integer, Set<Integer>> adj = new HashMap<>();
        int[] deg = new int[n]; // degree of each node

        // Sort by row (x), then col (y)
        Arrays.sort(ext, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
                return Integer.compare(a[1], b[1]);
            }
        });

        int[] prv = new int[] { -1, -1, -1 };
        for (int[] stone : ext) {
            if (stone[0] == prv[0]) {
                int u = stone[2];
                int v = prv[2];
                adj.computeIfAbsent(u, k -> new HashSet<>()).add(v);
                adj.computeIfAbsent(v, k -> new HashSet<>()).add(u);
                deg[u]++;
                deg[v]++;
            }
            prv = stone;
        }

        // Sort by col (y), then row (x)
        Arrays.sort(ext, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if (a[1] != b[1]) return Integer.compare(a[1], b[1]);
                return Integer.compare(a[0], b[0]);
            }
        });

        prv = new int[] { -1, -1, -1 };
        for (int[] stone : ext) {
            if (stone[1] == prv[1]) {
                int u = stone[2];
                int v = prv[2];
                adj.computeIfAbsent(u, k -> new HashSet<>()).add(v);
                adj.computeIfAbsent(v, k -> new HashSet<>()).add(u);
                deg[u]++;
                deg[v]++;
            }
            prv = stone;
        }

        // Min-heap on degree
        PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return Integer.compare(a[0], b[0]); // compare degree
            }
        });

        for (int i = 0; i < n; i++) {
            if (deg[i] > 0) {
                pq.offer(new int[] { deg[i], i });
            }
        }

        boolean[] seen = new boolean[n];
        int ret = 0;

        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int degree = top[0];
            int cur = top[1];

            // Skip if already processed or degree changed
            if (seen[cur] || deg[cur] != degree) continue;

            seen[cur] = true;
            ret++;

            if (!adj.containsKey(cur)) continue;

            for (int nxt : adj.get(cur)) {
                deg[nxt]--;
                if (deg[nxt] > 0) {
                    pq.offer(new int[] { deg[nxt], nxt });
                }
            }
        }

        return ret;
    }
}