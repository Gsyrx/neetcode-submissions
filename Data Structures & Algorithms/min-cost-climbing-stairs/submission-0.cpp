class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        if (n == 0) return 0;
        if (n == 1) return cost[0];

        // Use two variables to store the minimum cost to reach the previous two steps
        int prev1 = cost[0], prev2 = cost[1];

        for (int i = 2; i < n; ++i) {
            int current = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = current;
        }

        // Return the minimum cost to reach the last or second-to-last step
        return min(prev1, prev2);
    }
};
