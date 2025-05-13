class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, bool> mapping;
        int n = nums.size();
        bool flag = false;
        int maxi = INT_MIN;

        for (int i=0; i<n; i++){
            if (nums[i]>=0){
                flag = true;
            }
            if (nums[i] > 0 && mapping.find(nums[i])==mapping.end()){
                ans = ans + nums[i];
                mapping[nums[i]] = true;
            }
            maxi = max(maxi, nums[i]);
        }

        return (flag) ? ans : maxi;
    }
};