class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count the frequency of each task
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Sort the frequencies in descending order
        sort(freq.begin(), freq.end(), greater<int>());

        // Max frequency and number of tasks with max frequency
        int maxFreq = freq[0];
        int maxCount = 1;

        for (int i = 1; i < 26; i++) {
            if (freq[i] == maxFreq) {
                maxCount++;
            } else {
                break;
            }
        }

        // Calculate the minimum intervals required
        int partCount = maxFreq - 1;
        int partLength = n - (maxCount - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.size() - (maxFreq * maxCount);
        int idles = max(0, emptySlots - availableTasks);

        return tasks.size() + idles;
    }
};