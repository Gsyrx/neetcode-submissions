class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count the frequency of each element
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        // Step 2: Use a min-heap (priority queue) to keep track of the top k elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        for (const auto& entry : freqMap) {
            minHeap.push({entry.second, entry.first}); // Push frequency and number as a pair
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the element with the lowest frequency
            }
        }

        // Step 3: Extract the elements from the heap into the result vector
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
