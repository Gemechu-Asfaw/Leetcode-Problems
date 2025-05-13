class Solution {
private:
    int solve(int m, int n, vector<vector<int>> &dp){
        if (m==1 || n==1){
            return 1;
        } else if (dp[m-1][n-1] != -1){
            return dp[m-1][n-1];
        } else {
            return dp[m-1][n-1] = solve(m-1, n, dp) + solve(m, n-1, dp);
        }
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m, n, dp);
    }
};