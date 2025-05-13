class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int firstFlag = matrix[0][0] == 0 ? 3 : 0;
        int start;

        // flaging the first cell from row and from column of current cell if it is 0
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    if (i==0) firstFlag = firstFlag | 2;            // flaging for the row
                    else if (j==0) firstFlag = firstFlag | 1;       // flaging for the column
                }
            }
        }

        // setting the values of entire row it's first cell is 0
        for (int i=1; i<m; i++){
            if (matrix[i][0] == 0){
                for (int j=0; j<n; j++){
                    matrix[i][j] = 0;
                }  
            }
        }

        // setting the values of entire column it's first cell is 0
        for (int i=1; i<n; i++){
            if (matrix[0][i] == 0){
                for (int j=0; j<m; j++){
                    matrix[j][i] = 0;
                }  
            }
        }

        // solving the case for the flag related to matrix[0][0]
        if (firstFlag & 2){
            for (int i=0; i<n; i++){
                matrix[0][i] = 0;
            }
        }

        if (firstFlag & 1){
            for (int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};