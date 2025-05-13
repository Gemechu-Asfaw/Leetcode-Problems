class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int n = nums.size(), sum = 0, ans = 0;

        for (int i=0; i<n; i++){
            sum = sum + nums[i];
            if (sum == k){
                ans++;
            }
            ans = ans + count[sum-k];
            count[sum]++;
        }

        return ans;
    }
};