class Solution {
public:

    bool backtrack(vector<vector<char>>& board, const string& word, int i, int j, int index) {
        // Base case: if index equals the word length, we found the word
        if (index == word.size()) return true;

        // Check if we are out of bounds or if the current character doesn't match
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }

        // Save the character at (i, j) and mark it as visited
        char temp = board[i][j];
        board[i][j] = '#'; // mark as visited

        // Explore all 4 possible directions
        bool found = backtrack(board, word, i + 1, j, index + 1) ||  // down
                     backtrack(board, word, i - 1, j, index + 1) ||  // up
                     backtrack(board, word, i, j + 1, index + 1) ||  // right
                     backtrack(board, word, i, j - 1, index + 1);    // left

        // Restore the original character at (i, j)
        board[i][j] = temp;

        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) return false;

        int rows = board.size();
        int cols = board[0].size();

        // Loop through every cell in the board
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Start backtracking from each cell
                if (backtrack(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
