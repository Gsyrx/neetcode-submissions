class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));  // Memoization table
        
        int longestPath = 0;

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // DFS function to explore the longest path from (i, j)
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (memo[i][j] != -1) return memo[i][j];  // Return the result if already computed
            
            int maxPath = 1;  // Minimum path length is 1 (the cell itself)
            
            for (auto& dir : directions) {
                int ni = i + dir.first, nj = j + dir.second;
                
                // Check if the next cell is within bounds and the value is increasing
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] > matrix[i][j]) {
                    maxPath = max(maxPath, 1 + dfs(ni, nj));  // Explore the next cell
                }
            }

            memo[i][j] = maxPath;  // Store the result in memoization table
            return maxPath;
        };

        // Try starting the DFS from every cell
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                longestPath = max(longestPath, dfs(i, j));  // Update the longest path found
            }
        }

        return longestPath;
    }
};
