class Solution {
public:

    // Helper function to perform DFS and calculate the area of the island
    int dfs(vector<vector<int>>& grid, int i, int j) {
        // If out of bounds or water (0), return 0
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }

        // Mark the current cell as visited (set to water '0')
        grid[i][j] = 0;
        
        // Initialize area as 1 (the current land cell)
        int area = 1;

        // Explore all four directions (down, up, right, left)
        area += dfs(grid, i + 1, j);  // down
        area += dfs(grid, i - 1, j);  // up
        area += dfs(grid, i, j + 1);  // right
        area += dfs(grid, i, j - 1);  // left

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        // Traverse the grid
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                // If the cell is land (1), perform DFS to find the area of the island
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }

        return maxArea; 
    }
};
