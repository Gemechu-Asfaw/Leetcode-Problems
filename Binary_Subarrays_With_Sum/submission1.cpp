class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> map;
        int n = nums.size(), sum = 0, ans = 0;
        for (int i=0; i<n; i++){
            sum = sum + nums[i];
            if (sum == goal){
                ans++;
            }
            ans = ans + map[sum-goal];
            map[sum]++;
        }

        return ans;
    }
};