class Solution {
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Base case: out of bounds or current cell is water
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0'; // Mark the current land as visited

        // Explore all 4 directions (up, down, left, right)
        dfs(grid, i - 1, j); // Up
        dfs(grid, i + 1, j); // Down
        dfs(grid, i, j - 1); // Left
        dfs(grid, i, j + 1); // Right
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int numIslands = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    numIslands++;      // Found an unvisited island
                    dfs(grid, i, j);   // Mark the entire island as visited
                }
            }
        }

        return numIslands;
    }
};