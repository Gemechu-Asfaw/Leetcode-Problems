class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> prev(n);

        for (int i=0; i<n; i++){
            if (obstacleGrid[0][i] == 1 || (i>0 && prev[i-1]==0)){
                prev[i] = 0;
            } else {
                prev[i] = 1;
            }
        }

        for (int i=1; i<m; i++){
            vector<int> curr(n);

            for (int j=0; j<n; j++){
                if (j==0){
                    curr[j] = (obstacleGrid[i][j] == 1 || prev[j] == 0) ? 0 : 1;
                } else {
                    if (obstacleGrid[i][j] == 1){
                        curr[j] = 0;
                    } else {
                        curr[j] = curr[j-1] + prev[j];
                    }
                }
            }

            prev = curr;
        }

        return prev[n-1];
    }
};