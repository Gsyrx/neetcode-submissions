class Solution {
public:

    // Helper DFS function
    void dfs(vector<vector<char>>& board, int x, int y) {
        int rows = board.size();
        int cols = board[0].size();

        // If out of bounds or not an 'O', return
        if (x < 0 || x >= rows || y < 0 || y >= cols || board[x][y] != 'O') {
            return;
        }

        // Mark the current 'O' as safe
        board[x][y] = 'S';

        // Explore all four directions (up, down, left, right)
        dfs(board, x + 1, y); // down
        dfs(board, x - 1, y); // up
        dfs(board, x, y + 1); // right
        dfs(board, x, y - 1); // left
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int rows = board.size();
        int cols = board[0].size();

        // Step 1: DFS from the border 'O's
        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0); // First column
            if (board[i][cols - 1] == 'O') dfs(board, i, cols - 1); // Last column
        }
        for (int j = 0; j < cols; ++j) {
            if (board[0][j] == 'O') dfs(board, 0, j); // First row
            if (board[rows - 1][j] == 'O') dfs(board, rows - 1, j); // Last row
        }

        // Step 2: Convert the surrounded 'O's to 'X's and 'S' back to 'O'
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // Surrounded 'O' turned into 'X'
                } else if (board[i][j] == 'S') {
                    board[i][j] = 'O'; // Safe 'O' turned back to 'O'
                }
            }
        }
    }
};
