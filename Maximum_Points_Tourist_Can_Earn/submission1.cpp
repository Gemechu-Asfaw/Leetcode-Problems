class Solution {
public:
    int solve(int k, int currentDay, int n, int currentCity, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore, vector<vector<int>> &dp){

        if (currentDay==k) return 0;
        else if (dp[currentCity][currentDay] != -1) return dp[currentCity][currentDay];

        int ans = INT_MIN;
        for (int i=0; i<n; i++){
            if (i==currentCity){
                ans = max(ans, stayScore[currentDay][currentCity] + solve(k, currentDay+1, n, currentCity, stayScore, travelScore, dp));
            } else {
                ans = max(ans, travelScore[currentCity][i] + solve(k, currentDay+1, n, i, stayScore, travelScore, dp));
            }
        }

        return dp[currentCity][currentDay] = ans;
    }

    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {

        vector<vector<int>> dp(n, vector<int>(k, -1));
        int ans = INT_MIN;

        for (int i=0; i<n; i++){
            ans = max(ans, solve(k, 0, n, i, stayScore, travelScore, dp));
        }

        return ans;
    }
};