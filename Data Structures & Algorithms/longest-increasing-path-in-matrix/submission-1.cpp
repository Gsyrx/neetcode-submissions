class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1)); // Memoization table

        int maxLength = 0;

        // Direction vectors for up, down, left, and right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Helper function to perform DFS with memoization
        function<int(int, int)> dfs = [&](int x, int y) {
            if (memo[x][y] != -1) {
                return memo[x][y];  // If the result is already computed, return it
            }

            int maxPath = 1;  // At least the current cell itself

            // Explore all four directions
            for (auto& dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;
                // Check if the new cell is within bounds and has a larger value
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > matrix[x][y]) {
                    maxPath = max(maxPath, 1 + dfs(nx, ny));
                }
            }

            memo[x][y] = maxPath;  // Memoize the result
            return maxPath;
        };

        // Try to start from every cell in the matrix
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                maxLength = max(maxLength, dfs(i, j));
            }
        }

        return maxLength;
    }
};
