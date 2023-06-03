class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;
        
        // Check if the first row or column needs to be set to zero
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    if(i == 0) firstRowZero = true;
                    if(j == 0) firstColZero = true;
                    matrix[i][0] = 0; // mark the first element of row
                    matrix[0][j] = 0; // mark the first element of column
                }
            }
        }
        
        // Set rows to zero
        for(int i = 1; i < m; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Set columns to zero
        for(int j = 1; j < n; j++) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Set the first row and column to zero if needed
        if(firstRowZero) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        
        if(firstColZero) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
