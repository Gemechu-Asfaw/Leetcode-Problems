class Solution {
public:
    bool solve(string s, int n, int index, int state, vector<vector<int>> &dp){
        if (index==n){
            return state==0;
        } else if (state == -1){
            return false;
        } else if (dp[index][state] != -1){
            return dp[index][state];
        } else if (s[index] == '('){
            return dp[index][state] = solve(s, n, index+1, state+1, dp);
        } else if (s[index] == ')'){
            return dp[index][state] = solve(s, n, index+1, state-1, dp);
        } return dp[index][state] = solve(s, n, index+1, state+1, dp) || solve(s, n, index+1, state-1, dp) || solve(s, n, index+1, state, dp);
    }

    bool checkValidString(string s) {
        int n = s.size(), state = 0, index = 0;
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return solve(s, n, index, state, dp);
    }
};