class Solution {
private:
    int solve(vector<vector<int>>& grid, vector<vector<int>> &dp, int m, int n){
        if (m<0 || n<0){
            return (int)1e9;
        } else if (m==0 && n==0){
            return grid[0][0];
        } else if (dp[m][n] != -1){
            return dp[m][n];
        } else {
            int up = grid[m][n] + solve(grid, dp, m-1, n);
            int left = grid[m][n] + solve(grid, dp, m, n-1);
            return dp[m][n] = min(up, left);
        }
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(grid, dp, m-1, n-1);
    }
};