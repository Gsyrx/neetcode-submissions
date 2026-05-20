class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
        return {};
    }

    // Sort intervals by start time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;
    result.push_back(intervals[0]);  // Add the first interval to start with

    for (int i = 1; i < intervals.size(); ++i) {
        // Get the last added interval in the result
        vector<int>& last = result.back();
        
        // Check if there is an overlap
        if (last[1] >= intervals[i][0]) {
            // Merge the intervals by updating the end of the last interval
            last[1] = max(last[1], intervals[i][1]);
        } else {
            // No overlap, so we add the current interval to the result
            result.push_back(intervals[i]);
        }
    }

    return result;
    }
};
