class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int m, int n){
        if (m<0 || n<0 || obstacleGrid[m][n]==1){
            return 0;
        } else if (m==0 && n==0){
            return 1;
        } else if (dp[m][n] != -1){
            return dp[m][n];
        } else {
            return dp[m][n] = solve(obstacleGrid, dp, m-1, n) + solve(obstacleGrid, dp, m, n-1);
        }
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(obstacleGrid, dp, m-1, n-1);
    }
};