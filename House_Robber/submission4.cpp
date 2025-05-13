class Solution {
public:
    int solve(vector<int> &nums, vector<int> &dp, int n){
        if (n<0) return 0;
        else if (n==0) return nums[0];
        else if (dp[n] != -1) return dp[n];
        int chosen = nums[n] + solve(nums, dp, n-2);
        int notChosen = solve(nums, dp, n-1);
        return dp[n] = max(chosen, notChosen);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, dp, n-1);
    }
};