class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;  // No profit if prices are empty

        int minPrice = prices[0];  // Initialize minPrice with the first price
        int maxProfit = 0;  // Initialize maxProfit to 0

        for (int i = 1; i < prices.size(); ++i) {
            // Update minPrice if a lower price is found
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            // Calculate the potential profit if we sold on day i
            int currentProfit = prices[i] - minPrice;
            // Update maxProfit if currentProfit is higher
            maxProfit = max(maxProfit, currentProfit);
        }

        return maxProfit;
    }
};
