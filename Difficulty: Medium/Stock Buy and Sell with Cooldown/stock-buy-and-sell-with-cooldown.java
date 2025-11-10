class Solution {
    int[][] dp;
    public int maxProfit(int[] arr) {
        int n = arr.length;
        dp = new int[n][2];          // dp[i][0 or 1] means the max profit at day i with 0=not holding stock or 1=holding stock
        for (int[] row : dp)
            Arrays.fill(row, -1);
        return solve(arr, 0, 0);
    }

    private int solve(int[] arr, int curr, int holding) {
        // holding = 0 means no stock currently held, holding = 1 means stock is held
        if (curr >= arr.length)
            return 0;

        if (dp[curr][holding] != -1)
            return dp[curr][holding];

        int idle = solve(arr, curr + 1, holding);  // skip current day

        if (holding == 0) {
            // If not holding a stock:
            // 1) Buy stock at current day price (cost price arr[curr])
            int buy = solve(arr, curr + 1, 1) - arr[curr];
            dp[curr][holding] = Math.max(buy, idle);
        } else {
            // If holding a stock:
            // 1) Sell the stock today and cooldown next day
            int sell = arr[curr] + solve(arr, curr + 2, 0); // cooldown after selling
            dp[curr][holding] = Math.max(sell, idle);
        }
        return dp[curr][holding];
    }
}