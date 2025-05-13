class Solution {
private:
    int solve(vector<vector<int>>& matrix, vector<vector<int>> &dp, int x, int y, int n){
        if (y<0 || y>=n){
            return (int)1e9;
        } else if (x == n-1){
            return dp[x][y] = matrix[x][y];
        } else if (dp[x][y] != -1000){
            return dp[x][y];
        } else {
            int downStraight = solve(matrix, dp, x+1, y, n);
            int downLeft = solve(matrix, dp, x+1, y-1, n);
            int downRight = solve(matrix, dp, x+1, y+1, n);
            return dp[x][y] = matrix[x][y] + min(downStraight, min(downLeft, downRight));
        }
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1000));
        int ans = INT_MAX;

        for (int i=0; i<n; i++){
            ans = min(ans, solve(matrix, dp, 0, i, n));
        }

        return ans;
    }
};