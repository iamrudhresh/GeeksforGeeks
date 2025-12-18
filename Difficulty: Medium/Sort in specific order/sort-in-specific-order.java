class Solution {
    public void sortIt(int[] arr) {
        // Step 1: Convert int[] to Integer[]
        Integer[] temp = Arrays.stream(arr).boxed().toArray(Integer[]::new);

        // Step 2: Sort with custom comparator
        Arrays.sort(temp, (a, b) -> {
            if (a % 2 == 0 && b % 2 == 1) {
                return 1; // even before odd
            } else if (a % 2 == 0 && b % 2 == 0) {
                return a - b; // ascending even numbers
            } else if (a % 2 == 1 && b % 2 == 1) {
                return b - a; // descending odd numbers
            } else if (a % 2 == 1 && b % 2 == 0) {
                return -1; // odd after even
            }
            return 0;
        });

        // Step 3: Copy back sorted elements to original array
        for (int i = 0; i < arr.length; i++) {
            arr[i] = temp[i];
        }
    }
}