class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;

        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());  // Sort to create a common key for anagrams
            anagramMap[key].push_back(str); // Group anagrams together
        }

        vector<vector<string>> result;
        for (auto& pair : anagramMap) {
            result.push_back(pair.second); // Collect grouped anagrams
        }

        return result;
    }
};