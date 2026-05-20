class Solution {
public:

    // Function to perform DFS traversal and mark visited land cells
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Base case: out of bounds or water ('0')
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        
        // Mark the current cell as visited (water '0')
        grid[i][j] = '0';
        
        // Explore all four directions
        dfs(grid, i + 1, j);  // down
        dfs(grid, i - 1, j);  // up
        dfs(grid, i, j + 1);  // right
        dfs(grid, i, j - 1);  // left
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }

        int islandCount = 0;

        // Traverse the entire grid
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                // If we find land ('1'), it's the start of a new island
                if (grid[i][j] == '1') {
                    islandCount++;
                    dfs(grid, i, j);  // Mark all connected land as visited
                }
            }
        }

        return islandCount;
    }
};
