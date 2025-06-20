class Solution {
    public boolean validgroup(int[] arr, int k) {
        // code here
          int n = arr.length;

        // Edge‑case 1: If each group must contain only one element
        if (k == 1) return true;

        // Edge‑case 2: If total length is not divisible by k, impossible
        if (n % k != 0) return false;

        // Step 1: Sort the array so consecutive numbers are adjacent
        Arrays.sort(arr);

        // Step 2: Build a frequency map of all numbers
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        for (int num : arr) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }

        // Step 3: Try to form groups starting from the smallest numbers
        for (int i = 0; i < n; i++) {
            // If this number is already used in previous groups, skip
            int count = freqMap.get(arr[i]);
            if (count == 0) continue;

            // Use one occurrence of arr[i]
            freqMap.put(arr[i], count - 1);

            // Attempt to build the rest of the group: arr[i]+1, arr[i]+2, …, arr[i]+(k‑1)
            for (int offset = 1; offset < k; offset++) {
                int next = arr[i] + offset;

                // If next needed number is missing or exhausted → invalid
                if (freqMap.getOrDefault(next, 0) == 0) {
                    return false;
                }
                // Consume one occurrence of that number
                freqMap.put(next, freqMap.get(next) - 1);
            }
        }

        // If we never failed, grouping is possible
        return true;
    }
}