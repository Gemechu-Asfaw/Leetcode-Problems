class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], maxi = nums[0], n = nums.size(), i = 0, j = 0;
        while (j < n){
            while (sum < 0){
                sum = sum - nums[i];
                i++;
            }

            j++;
            if (j<n){
                sum = sum + nums[j];
                maxi = max(sum, maxi);
            }
        }

        return maxi;
    }
};