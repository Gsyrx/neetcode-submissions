class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap; // To store frequency of each number

        // Step 1: Count the frequency of each element
        for (int num : nums) {
            freqMap[num]++;
        }

        // Step 2: Min-heap to store the top k elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto& entry : freqMap) {
            minHeap.push({entry.second, entry.first}); // (frequency, number)
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the least frequent element
            }
        }

        // Step 3: Extract elements from the heap
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};