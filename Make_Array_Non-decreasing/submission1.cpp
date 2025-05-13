class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size(), ans = 0, maxi = INT_MIN;
        for (int i=0; i<n; i++){
            if (nums[i] >= maxi){
                ans++;
                maxi = max(maxi, nums[i]);
            }
        }

        return ans;
    }
};