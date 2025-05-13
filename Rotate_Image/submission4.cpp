class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        // Adding 1000 to each value in a matrix so that all elements become positive
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                matrix[i][j] = matrix[i][j] + 1000;
            }
        }

        // Now solving the problem by storing two numbers in a single place
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                int value = (matrix[i][j])%2001;
                matrix[j][n-i-1] = matrix[j][n-i-1] + value*2001;
            }
        }

        // Now getting the values by dividing the matrix elements by dividing with 2001
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                matrix[i][j] = (matrix[i][j])/2001;
            }
        }

        // Subtracting the elements with 1000 to get the original elements
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                matrix[i][j] = matrix[i][j] - 1000;
            }
        }
    }
};