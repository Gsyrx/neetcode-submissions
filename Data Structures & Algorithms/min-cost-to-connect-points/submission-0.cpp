class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        // Min-heap (priority queue) to store edges as (cost, point index)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Keep track of whether a point is already in the MST
        vector<bool> inMST(n, false);
        
        // Start with the first point (index 0)
        pq.push({0, 0});  // {cost, point index}
        int totalCost = 0;
        int edgesUsed = 0;
        
        while (edgesUsed < n) {
            // Extract the point with the minimum cost
            auto [cost, point] = pq.top();
            pq.pop();
            
            // If the point is already in the MST, continue to the next one
            if (inMST[point]) continue;
            
            // Add the cost to the total cost
            totalCost += cost;
            edgesUsed++;
            inMST[point] = true;
            
            // Add all the neighboring points to the priority queue
            for (int next = 0; next < n; next++) {
                if (!inMST[next]) {
                    int dist = abs(points[point][0] - points[next][0]) + abs(points[point][1] - points[next][1]);
                    pq.push({dist, next});
                }
            }
        }
        
        return totalCost;
    }
};