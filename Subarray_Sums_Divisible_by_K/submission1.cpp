class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int> mapping;
        int sum = 0, n = nums.size(), ans = 0;
        mapping[sum] = 1;

        for (int i=0; i<n; i++){
            sum = (sum + (nums[i]>=0 ? nums[i] : nums[i] + k*(-nums[i]/k + 1))) % k;     // brackets are necessary here otherwise evalution will br sum = sum + nums[i]>=0
            ans = ans + mapping[sum];
            mapping[sum]++;
        }

        return ans;
    }
};