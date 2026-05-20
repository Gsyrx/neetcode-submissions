class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;

public:
    // Constructor
    TimeMap() {}

    // Set operation
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }

    // Get operation
    string get(string key, int timestamp) {
        if (store.find(key) == store.end()) return "";

        vector<pair<int, string>>& entries = store[key];
        int left = 0, right = entries.size() - 1;
        string result = "";

        // Binary search for the largest timestamp <= given timestamp
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (entries[mid].first == timestamp) {
                return entries[mid].second; // Exact match found
            } 
            else if (entries[mid].first < timestamp) {
                result = entries[mid].second; // Potential result
                left = mid + 1;               // Search in the right half
            } 
            else {
                right = mid - 1;              // Search in the left half
            }
        }

        return result; // Return the closest previous value
    }
};