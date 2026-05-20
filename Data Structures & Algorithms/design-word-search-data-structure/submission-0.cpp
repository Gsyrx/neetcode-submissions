class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    // Helper function for search with support for '.'
    bool searchHelper(string& word, int index, TrieNode* node) {
        if (index == word.size()) {
            return node->isEndOfWord;
        }

        char ch = word[index];

        // Wildcard character '.'
        if (ch == '.') {
            for (auto& child : node->children) {
                if (searchHelper(word, index + 1, child.second)) {
                    return true;
                }
            }
            return false;
        }

        // Regular character
        if (node->children.find(ch) == node->children.end()) {
            return false;
        }

        return searchHelper(word, index + 1, node->children[ch]);
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Add a word to the dictionary
    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    // Search for a word (with support for '.' wildcard)
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};
