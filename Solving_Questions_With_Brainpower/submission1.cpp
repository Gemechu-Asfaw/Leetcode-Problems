class Solution {
public:
    long long solve(vector<vector<int>>& questions, vector<vector<long long>> &dp, int index, int n, int choice){
        if (index >= n){
            return 0;
        } else if (dp[index][choice] != -1){
            return dp[index][choice];
        } else {
            int value = questions[index][0];
            int skip = questions[index][1];
            if (choice == 0){
                return dp[index][choice] = max(solve(questions, dp, index+1, n, 0), solve(questions, dp, index+1, n, 1));
            } else {
                return dp[index][choice] = value + max(solve(questions, dp, index+skip+1, n, 0), solve(questions, dp, index+skip+1, n, 1));
            }
        }
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<vector<long long>> dp(n, vector<long long>(2,-1));
        return max(solve(questions, dp, 0, n, 0), solve(questions, dp, 0, n, 1));
    }
};