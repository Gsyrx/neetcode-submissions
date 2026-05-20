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
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        // Step 1: Sort the intervals in increasing order of start times
        vector<pair<int, int>> times;
        for (const auto& interval : intervals) {
            times.push_back({interval.start, 1});  // 1 for start time
            times.push_back({interval.end, -1});   // -1 for end time
        }
        
        sort(times.begin(), times.end());

        // Step 2: Sweep through the times to calculate the maximum rooms required
        int rooms = 0, currentRooms = 0;
        for (const auto& time : times) {
            currentRooms += time.second;  // Add 1 for a meeting start, subtract 1 for a meeting end
            rooms = max(rooms, currentRooms);  // Track the maximum number of rooms at any time
        }

        return rooms;
    }
};

