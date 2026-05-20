class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Variables to check if first row or column need to be zeroed
        bool zeroFirstRow = false;
        bool zeroFirstCol = false;
        
        // Check if the first row has any zero
        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == 0) {
                zeroFirstRow = true;
                break;
            }
        }

        // Check if the first column has any zero
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                zeroFirstCol = true;
                break;
            }
        }

        // Use first row and first column to mark the rows and columns
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Mark the start of the row
                    matrix[0][j] = 0; // Mark the start of the column
                }
            }
        }

        // Set the zeroes for the cells based on the marks
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set zeroes for the first row if needed
        if (zeroFirstRow) {
            for (int i = 0; i < n; ++i) {
                matrix[0][i] = 0;
            }
        }

        // Set zeroes for the first column if needed
        if (zeroFirstCol) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
