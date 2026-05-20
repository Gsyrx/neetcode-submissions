class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;  // Marks the end of a word

    TrieNode() {
        isEndOfWord = false;
    }
};

class PrefixTree {
private:
    TrieNode* root;

public:
    // Constructor
    PrefixTree() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;  // Mark the end of the word
    }

    // Search for an exact word in the Trie
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }

    // Check if any word starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }
};
