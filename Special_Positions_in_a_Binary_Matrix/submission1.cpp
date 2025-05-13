class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int row = mat.size(), col = mat[0].size();
        int ans = 0;

        // Traversing each cell of matrix
        for (int i=0; i<row; i++){
            for (int j=0; j<col; j++){

                if (mat[i][j]==1){
                    bool isSpecial = true;

                    // Traversing the entire row of cell
                    for (int k=0; k<col; k++){
                        if (mat[i][k]==1 && k!=j){
                            isSpecial = false;
                        }
                    }

                    // Traversing the entire column of cell
                    for (int k=0; k<row; k++){
                        if (mat[k][j]==1 && k!=i){
                            isSpecial = false;
                        }
                    }

                    // Incrementing the value of ans by 1 if special cell encountered
                    if (isSpecial==true){
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};