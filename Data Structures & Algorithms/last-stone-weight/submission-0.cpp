class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Max-heap: use priority_queue (default is max-heap)
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        while (maxHeap.size() > 1) {
            int stone1 = maxHeap.top(); maxHeap.pop(); // Heaviest
            int stone2 = maxHeap.top(); maxHeap.pop(); // Second heaviest

            if (stone1 != stone2) {
                maxHeap.push(stone1 - stone2); // Push the remaining weight
            }
            // If equal, both are destroyed (do nothing)
        }

        // If no stones left, return 0; otherwise return the last stone
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};