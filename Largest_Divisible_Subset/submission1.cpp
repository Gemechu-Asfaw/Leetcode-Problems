class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size(), index = 0, maxValue = 0;
        vector<int> ans;
        vector<pair<int, int>> dp(n);

        sort(nums.begin(), nums.end());

        for (int i=n-1; i>=0; i--){
            int current = nums[i], value = 1, next = -1;
            for (int j=i+1; j<n; j++){
                if (nums[j]%current==0 && dp[j].first+1 > value){
                    value = dp[j].first + 1;
                    next = j;
                }
            }

            dp[i] = {value, next};
            if (value > maxValue){
                maxValue = value;
                index = i;
            }
        }

        int currentIndex = index;
        while (currentIndex != -1){
            ans.push_back(nums[currentIndex]);
            currentIndex = dp[currentIndex].second;
        }

        return ans;
    }
};