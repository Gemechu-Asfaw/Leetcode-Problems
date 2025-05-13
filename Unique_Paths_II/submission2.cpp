class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        // For First row
        // for (int i=0; i<n; i++){
        //     if (obstacleGrid[0][i]==1 || (i>0 && dp[0][i-1]==0)){
        //         dp[0][i] = 0;
        //     }
        // }

        // // For First column
        // for (int i=0; i<m; i++){
        //     if (obstacleGrid[i][0]==1 || (i>0 && dp[i-1][0]==0)){
        //         dp[i][0] = 0;
        //     }
        // }

        // Remaining Grid
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                } else {
                    if (i>0 && j>0){
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                    } else if (i>0){
                        dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : dp[i-1][j];
                    } else if (j>0){
                        dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : dp[i][j-1];
                    } else {
                        dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : 1;
                    }
                }
            }
        }

        return dp[m-1][n-1];
    }
};