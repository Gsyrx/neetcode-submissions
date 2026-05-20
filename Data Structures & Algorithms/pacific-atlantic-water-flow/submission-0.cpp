

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<int>> result;

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // DFS function to mark reachable cells
        auto dfs = [&](int row, int col, vector<vector<bool>>& visited, auto&& dfs_ref) -> void {
            visited[row][col] = true;
            for (auto [dr, dc] : directions) {
                int newRow = row + dr;
                int newCol = col + dc;
                
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                    !visited[newRow][newCol] &&
                    heights[newRow][newCol] >= heights[row][col]) {
                    dfs_ref(newRow, newCol, visited, dfs_ref);
                }
            }
        };

        // Run DFS from Pacific (top and left edges)
        for (int i = 0; i < m; i++) {
            dfs(i, 0, pacific, dfs);         // Left column
            dfs(i, n - 1, atlantic, dfs);    // Right column
        }
        for (int j = 0; j < n; j++) {
            dfs(0, j, pacific, dfs);         // Top row
            dfs(m - 1, j, atlantic, dfs);    // Bottom row
        }

        // Find cells reachable by both oceans
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
