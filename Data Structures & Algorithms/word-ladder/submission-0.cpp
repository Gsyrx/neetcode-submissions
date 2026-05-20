class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If the endWord is not in the word list, return 0
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        // Queue to store the word and its level (distance from beginWord)
        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // Start from beginWord at level 1
        wordSet.erase(beginWord); // Remove the beginWord from the set to avoid revisiting
        
        while (!q.empty()) {
            string currentWord = q.front().first;
            int level = q.front().second;
            q.pop();
            
            // Try changing each character of the word
            for (int i = 0; i < currentWord.size(); i++) {
                char originalChar = currentWord[i];
                
                // Try all 26 possible letters for each position
                for (char c = 'a'; c <= 'z'; c++) {
                    currentWord[i] = c;
                    
                    // If the new word is the endWord, return the current level + 1
                    if (currentWord == endWord) {
                        return level + 1;
                    }

                    // If the new word exists in the wordSet, add it to the queue
                    if (wordSet.find(currentWord) != wordSet.end()) {
                        q.push({currentWord, level + 1});
                        wordSet.erase(currentWord); // Remove it from the set to avoid revisiting
                    }
                }
                
                // Restore the original character
                currentWord[i] = originalChar;
            }
        }
        
        // If no transformation sequence is found, return 0
        return 0;
    }
};
