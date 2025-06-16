class Solution {
  public:
    int getCost(vector<int> &heights, vector<int> &cost, int mid){
        int totalCost = 0, n = heights.size();
        for(int i = 0; i < n; ++i){
            // Cost for current tower: absolute difference * cost per unit
            totalCost += abs(mid - heights[i]) * cost[i];
        }
        return totalCost;
    }
    
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        // Initialize search boundaries with min and max heights
        int low = *min_element(heights.begin(), heights.end());
        int high = *max_element(heights.begin(), heights.end());
        int ans = INT_MAX; // To store the minimum cost found
        
        // Ternary search implementation
        while(low <= high) {
            // Calculate two mid-points dividing the range into thirds
            int mid1 = low + (high - low)/3;
            int mid2 = high - (high - low)/3;
            
            // Compute costs at these mid-points
            int cost1 = getCost(heights, cost, mid1);
            int cost2 = getCost(heights, cost, mid2);
            
            // Update the minimum cost found so far
            ans = min({ans, cost1, cost2});
            
            // Determine which segment to discard
            if(cost1 < cost2) {
                // Minimum is in the left segment, discard right
                high = mid2 - 1;
            } else {
                // Minimum is in the right segment, discard left
                low = mid1 + 1;
            }
        }
        
        return ans;
    }
};
