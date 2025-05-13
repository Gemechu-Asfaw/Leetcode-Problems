class Solution {
public:
    int solve(vector<int> &nums, vector<int> &dp, int n){
        if (n==0) return nums[0];
        else if (n==1) return max(nums[0], nums[1]);
        else if (dp[n] != -1) return dp[n];
        int first = solve(nums, dp, n-1);
        int second = nums[n] + solve(nums, dp, n-2);
        return dp[n] = max(first, second);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        vector<int> nums1, nums2;
        vector<int> dp1(n-1, -1), dp2(n-1, -1);

        for (int i=0; i<n; i++){
            if (i!=0) nums1.push_back(nums[i]);
            if (i!=n-1) nums2.push_back(nums[i]);
        }
        return max(solve(nums1, dp1, n-2), solve(nums2, dp2, n-2));
    }
};