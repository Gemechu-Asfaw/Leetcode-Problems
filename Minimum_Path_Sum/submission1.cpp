class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n, 0);

        for (int i=0; i<n; i++){
            if (i==0){
                prev[i] = grid[0][i];
            } else {
                prev[i] = grid[0][i] + prev[i-1];
            }
        }

        for (int i=1; i<m; i++){
            vector<int> curr(n, 0);
            for (int j=0; j<n; j++){
                if (j==0){
                    curr[j] = grid[i][j] + prev[j];
                } else {
                    curr[j] = grid[i][j] + min(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }

        return prev[n-1];
    }
};