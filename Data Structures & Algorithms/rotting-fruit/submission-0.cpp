class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Directions: up, down, left, right
        vector<int> dirs = {-1, 0, 1, 0, -1};
        
        queue<pair<int, int>> q; // To store the coordinates of rotten oranges
        int freshCount = 0; // To count the number of fresh oranges
        
        // Step 1: Add all the rotten oranges to the queue and count the fresh oranges
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j}); // Rotten orange
                }
                else if (grid[i][j] == 1) {
                    freshCount++; // Fresh orange
                }
            }
        }
        
        if (freshCount == 0) return 0; // No fresh oranges, so no time needed
        
        int minutes = 0; // Time elapsed
        int rottenCount = 0;
        
        // Step 2: BFS to rot the fresh oranges
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();
                
                // Check all 4 directions
                for (int d = 0; d < 4; ++d) {
                    int nx = x + dirs[d];
                    int ny = y + dirs[d + 1];
                    
                    // If the neighbor is a fresh orange, rot it
                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; // Make it rotten
                        q.push({nx, ny}); // Add to the queue for the next round
                        freshCount--; // Decrease the fresh orange count
                    }
                }
            }
            
            // Increment the minutes after one level of BFS
            if (!q.empty()) minutes++;
        }
        
        // Step 3: Check if there are still fresh oranges left
        return freshCount == 0 ? minutes : -1;
    }
};
