class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Step 1: Sort the intervals based on their end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Sort by end time
        });

        int count = 0;
        int lastEnd = intervals[0][1]; // The end of the first interval

        // Step 2: Iterate over the intervals
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < lastEnd) {
                // If current interval overlaps with the last one, increment the removal count
                count++;
            } else {
                // If no overlap, update the last end time
                lastEnd = intervals[i][1];
            }
        }

        return count;
    }
};
