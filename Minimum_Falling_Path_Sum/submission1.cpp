class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n);
        int ans = INT_MAX;

        for (int i=0; i<n; i++){
            prev[i] = matrix[n-1][i];
        }

        for (int i=n-2; i>=0; i--){
            vector<int> curr(n);
            for (int j=0; j<n; j++){
                int leftDiagonal = (j>0) ? prev[j-1] : (int)1e9;
                int rightDiagonal = (j<n-1) ? prev[j+1] : (int)1e9;
                int bottom = prev[j];
                curr[j] = matrix[i][j] + min(bottom, min(leftDiagonal, rightDiagonal));
            }
            prev = curr;
        }

        for (int i=0; i<n; i++){
            ans = min(ans, prev[i]);
        }

        return ans;
    }
};