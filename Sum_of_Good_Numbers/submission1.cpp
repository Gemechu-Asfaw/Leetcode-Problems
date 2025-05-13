class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for (int i=0; i<n; i++){
            if (i-k < 0){
                if (nums[i+k] < nums[i]){
                    ans = ans + nums[i];
                }
            } else if (i+k>=n){
                if (nums[i-k] < nums[i]){
                    ans = ans + nums[i];
                }
            } else if (nums[i]>nums[i-k] && nums[i]>nums[i+k]) {
                ans = ans + nums[i];
            }
        }

        return ans;
    }
};