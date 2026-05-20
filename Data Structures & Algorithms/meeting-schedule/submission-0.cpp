/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
        
        // Step 1: Sort the intervals by their start time
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start; // Sort by start time
        });

        // Step 2: Check for overlap
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[i-1].end) {
                // If the current meeting's start time is less than the previous meeting's end time
                return false; // Overlap detected
            }
        }

        return true; // No overlaps found
    }
};
