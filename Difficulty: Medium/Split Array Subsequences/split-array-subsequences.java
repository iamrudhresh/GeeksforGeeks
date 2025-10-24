class Solution {
    public boolean isPossible(int[] arr, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        Map<Integer, Integer> end = new HashMap<>();
         
        for (int n : arr) freq.put(n, freq.getOrDefault(n, 0) + 1);
         
        for (int n : arr) {
            if (freq.get(n) == 0) continue;
            if (end.getOrDefault(n - 1, 0) > 0) {
                end.put(n - 1, end.get(n - 1) - 1);
                end.put(n, end.getOrDefault(n, 0) + 1);
                freq.put(n, freq.get(n) - 1);
            } else {
                boolean canStart = true;
                for (int i = n; i < n + k; i++) {
                    if (freq.getOrDefault(i, 0) <= 0) {
                        canStart = false;
                        break;
                    }
                }
                 
                if (!canStart) return false;
                for (int i = n; i < n + k; i++) freq.put(i, freq.get(i) - 1);
                end.put(n + k - 1, end.getOrDefault(n + k - 1, 0) + 1);
            }
        }
        return true;
    }
}