class Solution {
public:
    vector<vector<string>> result;

    void backtrack(int n, int row, vector<string>& board, 
                   unordered_set<int>& cols, 
                   unordered_set<int>& diag1, 
                   unordered_set<int>& diag2) {
        if (row == n) {  // All queens are placed successfully
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            // Check if it's safe to place the queen
            if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col)) {
                continue;
            }

            // Place the queen
            board[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            // Move to the next row
            backtrack(n, row + 1, board, cols, diag1, diag2);

            // Backtrack: Remove the queen
            board[row][col] = '.';
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));  // Initialize an empty board
        unordered_set<int> cols;   // Track occupied columns
        unordered_set<int> diag1;  // Track occupied main diagonals (row - col)
        unordered_set<int> diag2;  // Track occupied anti-diagonals (row + col)

        backtrack(n, 0, board, cols, diag1, diag2);
        return result;
    }
};
