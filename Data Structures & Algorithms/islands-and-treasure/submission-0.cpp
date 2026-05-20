class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return;

        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;

        // Step 1: Enqueue all treasures (cells with value 0)
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Step 2: BFS to update distances
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int newRow = r + dr;
                int newCol = c + dc;

                // Skip out-of-bounds or walls
                if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || grid[newRow][newCol] != INT_MAX) {
                    continue;
                }

                // Update distance for the empty room
                grid[newRow][newCol] = grid[r][c] + 1;
                q.push({newRow, newCol});
            }
        }
    }
};
