class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Initialize sets for rows, columns, and sub-boxes
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> subBoxes(9);  // 3x3 sub-grids

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];
                if (num == '.') continue;  // Skip empty cells

                // Check row, column, and sub-box
                if (rows[i].count(num) || cols[j].count(num) || subBoxes[(i / 3) * 3 + j / 3].count(num)) {
                    return false;
                }

                // Add the number to the corresponding sets
                rows[i].insert(num);
                cols[j].insert(num);
                subBoxes[(i / 3) * 3 + j / 3].insert(num);
            }
        }
        return true;       
    }
};
