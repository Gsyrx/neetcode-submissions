class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-heap to keep the closest k points (pair: {distance, point})
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (auto& point : points) {
            int x = point[0], y = point[1];
            int dist = x * x + y * y;  // Squared distance

            maxHeap.push({dist, point});

            // Maintain only k closest points in the heap
            if (maxHeap.size() > k) {
                maxHeap.pop();  // Remove the farthest point
            }
        }

        // Extract the k closest points from the heap
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};