class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();
        vector<int> result(m, -1);
        
        // Step 1: Sort the intervals by their start time
        sort(intervals.begin(), intervals.end());
        
        // Step 2: Create a vector of queries with their original index
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < m; ++i) {
            sortedQueries.push_back({queries[i], i});
        }
        
        // Step 3: Sort queries based on their values
        sort(sortedQueries.begin(), sortedQueries.end());
        
        // Step 4: Min-heap for intervals
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        int idx = 0;  // Pointer to the current interval
        for (auto& query : sortedQueries) {
            int queryValue = query.first;
            int queryIndex = query.second;
            
            // Step 5: Add intervals that start before or at queryValue
            while (idx < n && intervals[idx][0] <= queryValue) {
                minHeap.push({intervals[idx][1] - intervals[idx][0] + 1, intervals[idx][1]});
                ++idx;
            }
            
            // Step 6: Remove intervals from heap that end before the queryValue
            while (!minHeap.empty() && minHeap.top().second < queryValue) {
                minHeap.pop();
            }
            
            // Step 7: If heap is not empty, the top is the minimum interval
            if (!minHeap.empty()) {
                result[queryIndex] = minHeap.top().first;
            }
        }
        
        return result;
    }
};
