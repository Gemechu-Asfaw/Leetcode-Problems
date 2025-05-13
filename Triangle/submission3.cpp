class Solution {
private:
    int solve(vector<vector<int>> &triangle, vector<vector<int>> &dp, int x, int y, int n){
        if (x==n-1){
            return triangle[x][y];
        } else if (dp[x][y] != -1){
            return dp[x][y];
        } else {
            int down = solve(triangle, dp, x+1, y, n);
            int downCross = solve(triangle, dp, x+1, y+1, n);
            return dp[x][y] = triangle[x][y] + min(down, downCross);
        }
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), x = 0, y = 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(triangle, dp, x, y, n);
    }
};